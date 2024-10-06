const time = Date.now()
let np = [2]

const npatrouver = 10000000

async function isprime(number) {
    let test = 0

    let max = Math.sqrt(nombre)

    while (np[test] <= max) {
        if (nombre % np[test] == 0) {
            return
        } else {
            test++
        }
    }
    np.push(nombre)
    return
}

let nombre = 3

while (np.length < npatrouver) {
    isprime(nombre)
    nombre += 2
}
console.log(npatrouver, "nombres premiers trouvés", Date.now() - time, "ms")
