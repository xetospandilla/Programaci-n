
/*--------------------------------------------------------------------------------------------
Fichero: practica1.js
Autor: Carlos Galán Cubells
Fecha: 05/02/2026
Descripción: Función que recibe un número real y lo multiplica por tres.
--------------------------------------------------------------------------------------------*/
//------------------------------------------------------------------------------------------
function integralTrozos(a, b, n, f, callback){  
    setTimeout( function(){                     
        const dx = (b-a) / n;                  
        let areaTotal = 0;                   

        for(let i=0; i<n; i++){                 
            let x = a + i * dx ;                 
            let altura = f(x);          
            let areaRectángulo= dx * altura;    
            areaTotal = areaTotal + areaRectángulo;   
        }
        callback(areaTotal);          
    }, 1500);                                        
}                   
// ------------- PRUEBA AUTOMÁTICA -----------------
const miFuncion = function(x){         
    return x * x;                       
}
const a1 = -5                 
const b1 = 15
const n = 100000

integralTrozos(a1, b1, n , miFuncion, function(resultado){
    if (resultado != 1166.6466667999923){
        console.log("Algo va mal");
    }
});
//------------------------------------------------------------------------------------------