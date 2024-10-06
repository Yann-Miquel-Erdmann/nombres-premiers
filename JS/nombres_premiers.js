
const time2 = Date.now();
let np = [];
let charged = []


const npatrouver =      100000000;
const numfichier =        5000000;

const fs = require('fs');


np.push(2) ;

charged.push(2);

console.log('starting')

    let s = 0;
    let nombre = 3;
    while(charged.length+(numfichier*s) < npatrouver){
        let test = 0 ;  
            
        let max = Math.sqrt(nombre) ;

        while (np[test] <= max) {
            
        
            if(np.length<test){
                np = []
                
                
                
                fs.readFileSync('np'+String(s)+'.csv', 'utf8', function (err, data) {
                    np = data.split(/\r?\n/);
                    data = 0
                }); 
                
                test = 0
                s++;
            
            }
            if(nombre%np[test]==0){
        
                nombre +=2 ;
                max = Math.sqrt(nombre) ;
                test = 0 ;
                if(s>1){
                    fs.readFileSync('./np2/np1.csv', 'utf8', function (err, data) {
                        np = data.split(/\r?\n/);
                        data = 0
                    }); 
                }
            } else {
                test++;
            }
        }

        
        
        charged.push(nombre);
        if(np.length < numfichier){
            np.push(nombre)
        }
        nombre += 2 ;
        

        
        if(s>1){
            fs.readFileSync('./np2/np1.csv', 'utf8', function (err, data) {
                np = data.split(/\r?\n/);
                data = 0
            }); 
        }    
        
        //------------------------------------------------------------

        if(charged.length == numfichier){
            let i = 0
            
            
            let show = "";
            while(i < charged.length){
                show = show+(String(charged[i]) + '\n');
                i++;
            }
            fs.writeFileSync("./np2/np"+String(s+1)+".csv", show);
            console.log("saved: "+"np"+String(s+1)+".csv");
            s++;
            
            
            charged = [];
        }

    //----------------------------------------------------------------

    
        
    
    }
    
console.log(npatrouver, 'nombres premiers trouvés et sauvegardés en ' , Date.now() - time2 , 'ms');
console.log(np[np.length-1])



