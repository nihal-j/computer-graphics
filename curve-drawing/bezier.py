import numpy as np

pascal = np.zeros((1000, 1000), dtype=np.int64)

def compute_bezier_curve(X, Y, numberOfPoints=1000):
    '''
        Finds the bezier curve for several points using de castlejau's algorithm.
    '''
    global pascal
    n = len(X) - 1
    bX = np.zeros(numberOfPoints)
    bY = np.zeros(numberOfPoints)

    t = 0.0
    step = 1/numberOfPoints
    ptCount = 0

    while ptCount < numberOfPoints:
        x = 0
        y = 0
        for i in range(n + 1):
            x += (pascal[n][i])*(t**i)*((1 - t)**(n - i))*X[i]
            y += (pascal[n][i])*(t**i)*((1 - t)**(n - i))*Y[i]
        bX[ptCount] = x
        bY[ptCount] = y
        ptCount += 1
        t += step

    return bX, bY

def compute_pascal_triangle(n=50):
    '''
        Utility function to calculate the pascal triangle.
    '''
    global pascal
    pascal[0][0] = 1
    for i in range(n + 1):
        for j in range(i + 1):
            if j == 0:
                pascal[i][j] = 1
            else:
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j]