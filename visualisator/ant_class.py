import matplotlib.pyplot as plt
import numpy as np
from matplotlib import animation

class ants:
    def __init__(self, pathCoordPerAnts, fig_animate, antIndex, x, y, end):
        self.pathCoordPerAnts = pathCoordPerAnts
        self.fig_animate = fig_animate
        self.antIndex = antIndex
        self.__data = x
        self.__data2 = y
        self.dots, = plt.plot([], [], 'o')
        self.i = 0
        self.flag = True
        self.end = end
    
    def animate(self, z):
        if self.__data[z] == int(self.end[1]) and self.__data2[z] == int(self.end[2]):
            self.flag = False
            return
        if self.flag:
            if (self.__data[z] == int(self.pathCoordPerAnts[self.antIndex][self.i][0]) and self.__data2[z] == int(self.pathCoordPerAnts[self.antIndex][self.i][1]) and self.i < len(self.pathCoordPerAnts[self.antIndex]) - 1):
                self.__data = np.linspace(int(self.pathCoordPerAnts[self.antIndex][self.i][0]), int(self.pathCoordPerAnts[self.antIndex][self.i + 1][0]), 100)
                self.__data2 = np.linspace(int(self.pathCoordPerAnts[self.antIndex][self.i][1]), int(self.pathCoordPerAnts[self.antIndex][self.i + 1][1]), 100)
                self.i += 1
            else:
                self.dots.set_data(self.__data[z], self.__data2[z])
            return self.dots

    def animate_ant(self, inter):
        return animation.FuncAnimation(self.fig_animate, self.animate, frames=100, interval=inter)