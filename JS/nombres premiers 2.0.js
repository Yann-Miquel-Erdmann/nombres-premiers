const time2 = Date.now()

let charged = []

const npatrouver = 10000000
const numfichier = 5000000

const fs = require("fs")

function isprime(nombre) {
    let max = Math.sqrt(nombre)
    let add_sub = -1
    let n = 1
    let test = 6 * n + add_sub

    while (test <= max) {
        if (nombre % test == 0) {
            return false
        } else {
            if (add_sub > 0) {
                n++
            }
            add_sub = add_sub * -1
            test = 6 * n + add_sub
        }
    }
    return true
}

//charged.push(2);charged.push(3)

console.log("starting")
let nombre_add_sub = -1
let nombre_n = 630001389
let s = 36

let nombre = 6 * nombre_n + nombre_add_sub

while (charged.length + s * numfichier < npatrouver) {
    if (isprime(nombre)) {
        charged.push(nombre)
    }

    if (nombre_add_sub > 0) {
        nombre_n++
    }
    nombre_add_sub = nombre_add_sub * -1

    nombre = 6 * nombre_n + nombre_add_sub

    //------------------------------------------------------------

    if (charged.length == numfichier) {
        let i = 0

        let show = ""
        while (i < charged.length) {
            show = show + (String(charged[i]) + "\n")
            i++
        }
        fs.writeFileSync("./np2/np" + String(s + 1) + ".csv", show)
        console.log("saved: " + "np" + String(s + 1) + ".csv")
        s++

        charged = []
    }
}

//----------------------------------------------------------------

console.log(
    npatrouver,
    "nombres premiers trouvés et sauvegardés en ",
    Date.now() - time2,
    "ms"
)
