# this program uses the pygame, time, and numpy libraries
import pygame, time, numpy, random
from pygame.locals import *
pygame.init()

# setting up the screen
width = int(input('maze width: '))
height = int(input('maze height: '))
size = int(input('node size: '))

screen = pygame.display.set_mode((width,height))
pygame.display.set_caption('Path Finding')


# Node class
class Node: 
    def __init__(self,x,y,num, size, width, height):
        global diagonals
        self.status = 0
        self.x = x
        self.y = y
        self.num = num
        self.explored = 10000
        self.children = []
        self.parent = 0
        self.size = size
        self.width = width
        self.height = height
        if  0<=self.x<=self.width-self.size and 0<=self.y+self.size<=self.height-self.size:
            self.children.append(self.num+self.width//self.size)
        if 0<=self.x<=self.width-self.size and 0<=self.y-self.size<=self.height-self.size:
            self.children.append(self.num-self.width//self.size)
        if 0<=self.x+self.size<=self.width-self.size and 0<=self.y<=self.height-self.size:
            self.children.append(self.num+1)
        if 0<=self.x-self.size<=self.width-self.size and 0<=self.y<=self.height-self.size:
            self.children.append(self.num-1)
        if 'y' in diagonals:
            if 0<=self.x-self.size<=self.width-self.size and 0<=self.y-self.size<=self.height-self.size:
                self.children.append(self.num-self.width//self.size-1)
            if 0<=self.x-self.size<=self.width-self.size and 0<=self.y+self.size<=self.height-self.size:
                self.children.append(self.num+self.width//self.size-1)
            if 0<=self.x+self.size<=self.width-self.size and 0<=self.y-self.size<=self.height-self.size:
                self.children.append(self.num-self.width//self.size+1)
            if 0<=self.x+self.size<=self.width-self.size and 0<=self.y+self.size<=self.height-self.size:
                self.children.append(self.num+self.width//self.size+1)
        random.shuffle(self.children)
    def draw(self):
        pygame.draw.rect(screen, (255-(self.status*255),255-(self.status*255),255-(self.status*255)),(self.x,self.y,self.size,self.size))

# maze class       
class Maze:
    def __init__(self, width, height, size):
        self.grid = []
        self.height = height
        self.width = width
        self.num = 0
        self.size = size
    def grid_setup(self):
        for y in range(0,self.height,self.size):
            for x in range(0,self.width,self.size):
                self.grid.append(Node(x,y,self.num,self.size,self.width,self.height))
                self.num+=1
        self.grid = numpy.array(self.grid)
        print(len(self.grid),type(self.grid))
    def draw(self):
        for x in range(0,self.width,self.size):
            pygame.draw.line(screen,(0,0,0),(x,0),(x,self.height),1)
        for y in range(0,self.height,self.size):
            pygame.draw.line(screen,(0,0,0),(0,y),(self.width,y),1)

diagonals = input('do you want to enable diagonals (y/n): ')

maze = Maze(width,height,size)
maze.grid_setup()
q = []
temp = []
current_node = 0
current_set = 0
current_time = time.time()

start = int(input('enter number of start node (0-'+str((width//size)*(height//size)-1)+'):'))
maze.grid[start].explored = 0
destination = int(input('enter number of destination node (0-'+str((width//size)*(height//size)-1)+'):'))
q.append([start])
d=0

print('''click on specific squares to make a wall
press f when you are ready to calculate a route''')

done = False
current_node = start
finding = False
screen.fill((255,255,255))

# mainloop
while True:
    if finding == False: # drawing
        if done == False:
            for node in maze.grid:
                node.draw()
        else:
            if current_set == 0:
                for node in maze.grid:
                    node.draw()
            current_node = destination
            while current_node!=start:
                pygame.draw.rect(screen,(0,255,255),(maze.grid[current_node].x,maze.grid[current_node].y,maze.grid[current_node].size,maze.grid[current_node].size))
                current_node = maze.grid[current_node].parent
            for nodes in q[current_set]:
                node = maze.grid[nodes]
                pygame.draw.rect(screen,(255,255,0),(node.x,node.y,node.size,node.size))
                if time.time()-current_time>0.25:
                    if current_set<len(q)-1:
                        current_set+=1
                        current_time = time.time()
                    else:
                        current_set = 0
                        current_time = time.time()
        pygame.draw.rect(screen,(255,0,0),(maze.grid[start].x,maze.grid[start].y,maze.grid[start].size,maze.grid[start].size))
        pygame.draw.rect(screen,(0,255,0),(maze.grid[destination].x,maze.grid[destination].y,maze.grid[destination].size,maze.grid[destination].size))
        maze.draw()
    else: # route calculation
        init = time.time()
        while done == False:
            for node in q[d]:
                for child in maze.grid[node].children:
                    if (maze.grid[child].explored>d and maze.grid[child].status == 0) or child == destination:
                        temp.append(child)
                        maze.grid[child].explored = d
                        maze.grid[child].parent = node
                        if child == destination:
                            done = True
            q.append(temp)
            if len(temp) == 0:
                print("Could not find route. Are you trying to trick me into trying to solve an impossible maze? Don't worry, I am not that stupid!")
                finding = False
                break
            temp = []
            d+=1
        finding = False
        print('time: '+str(time.time()-init))
        print('steps: '+ str(maze.grid[destination].explored))
    for event in pygame.event.get(): # events
        if event.type == QUIT:
            pygame.quit()
            exit()
        elif event.type == MOUSEBUTTONDOWN and event.button == 1:
            temp = [event.pos[0]//maze.size,event.pos[1]//maze.size]
            node = temp[1]*maze.width//maze.size+temp[0]
            node = maze.grid[node]
            if node.x<event.pos[0]<node.x+node.size and node.y<event.pos[1]<node.y+node.size:
                if node.status == 0:
                    node.status = 1
                else:
                    node.status = 0
        elif event.type == KEYDOWN and event.key ==K_f:
            finding = True
            temp = []
    pygame.display.update()

