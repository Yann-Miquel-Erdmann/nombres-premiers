const time = Date.now()
let np = [2]

const npatrouver = 1000000

let nombre = 3

while (np.length < npatrouver) {
    let test = 0

    let max = Math.sqrt(nombre)

    while (np[test] <= max) {
        if (nombre % np[test] == 0) {
            nombre += 2
            max = Math.sqrt(nombre)
            test = 0
        } else {
            test++
        }
    }

    np.push(nombre)
    nombre += 2
}
console.log(nombre - 2)
console.log(npatrouver, "nombres premiers trouvés", Date.now() - time, "ms")
