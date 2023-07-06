import matplotlib.pyplot as plt
import numpy as np
import os

with open('output.txt') as f:
  y = f.readlines()

size = len(y)

x = np.linspace(0, size, size)
for i in range(size):
  y[i] = int(y[i])

fig, ax = plt.subplots()
ax.plot(x, y)
plt.show()
plt.savefig('plot.png')