var veryCoolVariable;
let veryCoolScoped;
const veryCoolConstant;
var done = 1, wellDone, rare;
console.info( done ** ( function() {
  var result = 0;
  for( let i = done; i < done * 0xa; ++i ) result += i;
}) );
