/*--------------------------------------------------------------------
Diseña e implemente la función dividir
------------------------------------------------------*/
function dividir1(dividiendo, divisor){
    if(divisor == 0){

    } return dividiendo/divisor;
}
//--------------------------------------------------------------------

/*--------------------------------------------------------------------
Diseña e implemente la función dividir usando callbacks
------------------------------------------------------*/
function dividir2(a, b, callback){
    if(divisor == 0){
        callback("Division por 0", null)
        return
    }

    var resultado = dividiendo / divisor
    callback(null, resultado)
};
//--------------------------------------------------------------------
