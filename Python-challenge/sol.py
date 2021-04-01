import numpy as np
import json
from os import system
import time
grid = np.array([[0,0,0,0,1,0,1,0],[0,0,0,1,1,1,1,0],[0,0,1,0,1,0,1,0],[0,1,0,0,1,0,1,0]])

def get_live_ngb(grid , i , j):
    n ,m  = np.shape(grid)
    if i < 0 or i >= n or j < 0 or j >= m :
        return 0 
    count = 0 
    try :
        count += grid[i+1,j]
    except :
        pass 
    try :
        count += grid[i+1,j-1]
    except :
        pass 
    try :
        count += grid[i+1,j+1]
    except :
        pass 
    try :
        count += grid[i-1,j]
    except :
        pass 
    try :
        count += grid[i-1,j+1]
    except :
        pass 
    try :
        count += grid[i-1,j-1]
    except :
        pass 
    try :
        count += grid[i,j+1]
    except :
        pass 
    try :
        count += grid[i,j-1]
    except :
        pass 
    return count 

def print_grid(grid):
	_ = system('clear')
	n , m = np.shape(grid)
	for i in range(n):
		for j in range(m):
			str = "*" if grid[i,j] == 1 else " "
			print(str,end="")
		print()

	time.sleep(0.1)



def main( grid ):
	n ,m  = np.shape(grid)
	count = 1000 

	while count > 0 :
            print_grid(grid)
            print(count)
            count -= 1 
            flag = False
            for i in range(n):
    		        for j in range(m):
            	            nbg = get_live_ngb(grid , i , j)
            	            if grid[i,j] == 1 :
                	                if nbg < 2 or nbg > 3:
                    	                    grid[i,j] = 0 
                	                else  :
                    	                    grid[i,j] = 1
            	            elif nbg ==  3 :
                	                grid[i,j] = 1

        
        
def start():
	f = open('input.json',"r")      
	data = json.load(f)
	print("There are 10 grid available ")
	i = int(input("choose the number between 1 nad 10 "))
	print("")
	grid = np.array(data[str(i-1)])
	main( grid)  
	  
start()
