function middle(str) {
    let middle = Math.floor(str.length / 2);
    if(str.length%2 === 0) {
        return str.substring(middle-1, middle+1);
    } else {
        return str.substring(middle, middle+1);
    }
}

console.log(middle('good'));