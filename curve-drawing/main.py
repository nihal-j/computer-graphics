import numpy as np
import matplotlib.pyplot as plt
import bezier

X = np.array([])
Y = np.array([])
fig, ax = plt.subplots(figsize=(10, 8))
delete_state = 0
move_state = 0
mov_idx = -1
hovered = None

def is_plotted(x, y):
    global X, Y
    n = len(X)
    epsilon = 1e-2
    for i in range(n):
        try:
            if abs(X[i]-x) <= epsilon and abs(Y[i]-y) <= epsilon:
                return i
        except:
            pass
    return -1

def onclick(event):
    global X, Y, ax, fig, delete_state, move_state, mov_idx, hovered
    x = event.xdata
    y = event.ydata

    if delete_state == 2:
        delidx = is_plotted(x, y)
        X = np.delete(X, delidx)
        Y = np.delete(Y, delidx)

    if move_state == 2:
        delidx = is_plotted(x, y)
        mov_idx = delidx
        move_state = 3

    elif delete_state == 0 and move_state == 0:
        X = np.append(X, x)
        Y = np.append(Y, y)

    bX, bY = bezier.compute_bezier_curve(X, Y, numberOfPoints=10000)

    # points are ready to be plotted
    plt.clf()
    plt.autoscale(False)
    plt.plot(X, Y, color='red', alpha=0.3, marker='.', ms=10, mfc='green')
    plt.scatter(bX, bY, s=0.05)
    plt.draw()

def onkey(event):
    global X, Y, ax, fig, delete_state, move_state, mov_idx, hovered
    # print(event.key, event.xdata, event.ydata)
    if (event.key == 'x'):
        delete_state = not delete_state
        move_state = 0

    if (event.key == 'm'):
        move_state = not move_state
        delete_state = 0

def onmouse(event):
    global X, Y, ax, fig, delete_state, move_state, mov_idx, hovered

    if hovered != None:
        hovered.remove()
        hovered = None
        plt.draw()

    if delete_state:
        x = event.xdata
        y = event.ydata
        if is_plotted(x, y) != -1:
            # print(x, y)
            hovered, = plt.plot(x, y, marker='.', color='red', ms=20, alpha=0.3)
            delete_state = 2
            plt.draw()
        else:
            delete_state = 1

    if move_state:
        x = event.xdata
        y = event.ydata
        movidx = is_plotted(x, y)

        if move_state == 1 or move_state == 2:
            if movidx == -1:
                return
            hovered, = plt.plot(x, y, marker='.', color='green', ms=20, alpha=0.3)
            move_state = 2
            plt.draw()

        if move_state == 3:
            hovered, = plt.plot(x, y, marker='.', color='green', ms=20, alpha=0.3)
            X = np.delete(X, mov_idx)
            Y = np.delete(Y, mov_idx)
            X = np.insert(X, mov_idx, x)
            Y = np.insert(Y, mov_idx, y)
            bX, bY = bezier.compute_bezier_curve(X, Y, numberOfPoints=10000)
            plt.clf()
            plt.autoscale(False)
            plt.plot(X, Y, color='red', alpha=0.3, marker='.', ms=10, mfc='green')
            plt.scatter(bX, bY, s=0.05)
            plt.draw()

bezier.compute_pascal_triangle()
fig.canvas.mpl_connect('button_press_event', onclick)
fig.canvas.mpl_connect('key_press_event', onkey)
plt.connect('motion_notify_event', onmouse)

plt.show()