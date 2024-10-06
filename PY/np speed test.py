from time import time
from math import sqrt

time2 = time()
np = [2]

npatrouver = 100000
nplen = 1

nombre = 3

while (nplen < npatrouver):
    test = 0

    max = sqrt(nombre)
    while (np[test] <= max):
        if (nombre % np[test] == 0):
            nombre += 2
            max = sqrt(nombre)
            test = 0
        else:
            test += 1

    np.append(nombre)
    nplen += 1
    nombre += 2

print(npatrouver, "nombres premiers trouvés", time() - time2, "ms")
