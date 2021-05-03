import matplotlib.pyplot as plt
import numpy as np

x_points = np.array([1, 2, 6, 8])
y_points = np.array([3, 8, 1, 10])

figure = plt.figure()
plt.plot(x_points, y_points, marker='o')
plt.xlabel("X Axis Label")
plt.ylabel("Y Axis Label")
plt.grid()
plt.show()

figure.savefig("basic_chart.jpg")
