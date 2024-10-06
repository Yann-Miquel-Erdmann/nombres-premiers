const time2 = Date.now()
let np = []

const npatrouver = 1000000
const numfichier = 5000000

np.push(2)

let nombre = 3

while (np.length < npatrouver) {
    let test = 0

    let max = Math.sqrt(nombre)

    if (np.length % 50000000 == 0) {
        console.log(np.length)
    }
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

if (np.length == npatrouver) {
    console.log("saving")
    const time = Date.now()

    const fs = require("fs")
    let i = 0
    let s = 1
    while (i < np.length) {
        let show = ""
        while (i < numfichier * s) {
            show = show + (String(np[i]) + ",")
            i++
        }
        fs.writeFileSync("./np/np" + String(s) + ".csv", show)

        s++
    }

    console.log(
        npatrouver,
        "nombres premiers sauvegardés",
        Date.now() - time,
        "ms"
    )
    console.log(
        npatrouver,
        "nombres premiers trouvés et sauvegardés en ",
        Date.now() - time2,
        "ms"
    )
    console.log(Ep[np.length - 1])
}
