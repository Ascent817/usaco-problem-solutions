import matplotlib.pyplot as plt
import numpy as np

with open('output.txt') as f:
  y = f.readlines()

size = len(y)

x = np.arange(1, size + 1)
y = tuple(map(int, y))

fig, ax = plt.subplots()
ax.plot(x, y)
plt.savefig('plot.png')