import matplotlib.pyplot as plt

def print_max(filename):
    x = []
    y = []
    for line in open(filename, 'r'):
        xi, yi = line.strip().split(",")
        x.append(int(xi))
        y.append(float(yi))
    plt.title("Max fitness x gen")
    plt.xlabel('generation')
    plt.ylabel('distance')
    #plt.yticks(y)
    plt.plot(x, y)
    plt.show()

def print_prom(filename):
    x = []
    y = []
    for line in open(filename, 'r'):
        xi, yi = line.strip().split(",")
        x.append(int(xi))
        y.append(float(yi))
    plt.title("Prom fitness x gen")
    plt.xlabel('generation')
    plt.ylabel('distance')
    plt.plot(x, y, marker = 'o', c = 'g')
    
    plt.show()


def print_route(filename):
    x = []
    y = []
    for line in open(filename, 'r'):
        xi, yi = line.strip().split(",")
        x.append(int(xi))
        y.append(float(yi))
    plt.title("mapa de coordenadas")
    plt.xlabel('x')
    plt.ylabel('y')
    x.append(x[0])
    y.append(y[0])
    plt.plot(x, y, marker = 'o', c = 'g')
    plt.show()

print_max("RoutesDataMax.txt")
print_prom("RoutesDataProm.txt")
print_route("BestRouteGraph.txt")

