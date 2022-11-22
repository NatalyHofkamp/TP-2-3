import matplotlib.pyplot as plt


def PrintMax(filename):
    x = []
    y = []
    for line in open(filename, 'r'):
        xi, yi = line.strip().split(",")
        x.append(int(xi))
        y.append(float(yi))
    plt.title("Shortest distance per generation")
    plt.xlabel('generation')
    plt.ylabel('distance')
    plt.plot(x, y)
    plt.show()


def PrintMin(filename):
    x = []
    y = []
    for line in open(filename, 'r'):
        xi, yi = line.strip().split(",")
        x.append(int(xi))
        y.append(float(yi))
    plt.title("Largest distance per generation")
    plt.xlabel('generation')
    plt.ylabel('distance')
    plt.plot(x, y)
    plt.show()


def PrintProm(filename):
    x = []
    y = []
    for line in open(filename, 'r'):
        xi, yi = line.strip().split(",")
        x.append(int(xi))
        y.append(float(yi))
    plt.title("Average distance per generation")
    plt.xlabel('generation')
    plt.ylabel('distance')
    plt.plot(x, y, marker = 'o', c = 'g')
    
    plt.show()


def PrintRoute(filename):
    x = []
    y = []
    for line in open(filename, 'r'):
        xi, yi = line.strip().split(",")
        x.append(int(xi))
        y.append(float(yi))
    plt.title("Map of coordinates")
    plt.xlabel('x')
    plt.ylabel('y')
    x.append(x[0])
    y.append(y[0])
    plt.plot(x, y, marker = 'o', c = 'g')
    plt.show()



def main():
    # Please, comment the function that you don't want to execute
    # (the one that contains the graph that you don't want to display)
    PrintMax("RoutesDataMax.txt")
    PrintMin("RoutesDataMin.txt")
    PrintProm("RoutesDataProm.txt")
    PrintRoute("BestRouteGraph.txt")
if __name__ == "__main__":
    main()
