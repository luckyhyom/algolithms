function zip(str) {
    let result = []
    let count = 0;
    let temp = '';
    for (let i = 0; i < str.length; i++) {
        if (str[i] !== temp) {
            if(count > 1) {
                result.push(String(count));
            }
            count = 0;
            temp = str[i];
            result.push(str[i]);
        }
        count++;
        console.log(str[i],count);
    }
    return result.join('');
}

console.log(zip('KKHSSSSSSSE'));