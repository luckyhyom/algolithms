function circle(str) {
    let copy = str.toUpperCase();
    for (let i = 0; i < Math.ceil(str.length/2); i++) {
        if (copy[i] !== copy[(str.length-1)-i]) {
            return 'NO';
        }
    }
    return 'YES';
}
function circle2(str) {
    let copy = str.toUpperCase();
    if(copy.split('').reverse().join('') === copy) {
        return 'YES';
    }
    return 'NO'
}

console.log(circle2('gogoG'));