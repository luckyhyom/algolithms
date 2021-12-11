function onlyInt(str) {
    str = str.replace(/[^0-9]/g,'');
    return parseInt(str);
}
function onlyInt2(str) {
    let result = '';
    for (const s of str) {
        if (!isNaN(s)) {
            result += s;
        }
    }
    return parseInt(result);
}

console.log(onlyInt('g0en2T0s8eSoft'));