const temps = [0,20,30,40];

function filtrar(array, condición){
    
    var arrayFiltrado;
    condición = false;

    for(let i = 0; i < array.lenght; i++){
        if(condición != false){
            array[i] = arrayFiltrado[i];
        }
    }
}

function mapear(array, cambio){
    
    for(let i = 0; i < array.lenght; i++){
        array[i] = cambio;
    }

    
}