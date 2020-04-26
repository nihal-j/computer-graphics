import numpy as np
import matplotlib.pyplot as plt
import bezier

X = np.array([])
Y = np.array([])
fig, ax = plt.subplots()

def onclick(event):
    global X, Y, ax, fig
    x = event.xdata
    y = event.ydata
    X = np.append(X, x)
    Y = np.append(Y, y)
    bX, bY = bezier.compute_bezier_curve(X, Y, numberOfPoints=10000)

    # points are ready to be plotted
    plt.clf()
    plt.autoscale(False)
    plt.plot(X, Y, color='red', alpha=0.3, marker='.', ms=10, mfc='green')
    plt.scatter(bX, bY, s=0.05)
    plt.draw()

bezier.compute_pascal_triangle()
fig.canvas.mpl_connect('button_press_event', onclick)

plt.show()