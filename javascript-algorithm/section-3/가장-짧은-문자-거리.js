function distance(str, s) {
    let left = [];
    let right = [];
    let pos = 1000;
    let pos2 = 1000;
    for (let i = 0; i < str.length; i++) {
        
        if (str[i]===s) {
            pos = 0;
        } else {
            pos++;
        }
        left.push(pos);
    }
    for (let i = 0; i < str.length; i++) {
        if (str[(str.length-1)-i]===s) {
            pos2 = 0;
        } else {
            pos2++;
        }
        right.push(pos2);
    }
    right = right.reverse();
    return left.map((v, i) => {
        return Math.min(v,right[i]);
    });
}

console.log(distance('teachermode','e'));

function distance2(str, s) {
    let result = [];
    let pos = 1000;

    for (let i = 0; i < str.length; i++) {
        if (str[i] === s) {
            pos = 0;
        } else {
            pos++;
        }
        result.push(pos);
    }
    pos = 1000;
    for (let i = str.length-1; i >= 0; i--) {
        if (str[i] === s) {
            pos = 0;
        } else {
            pos++
            result[i] = Math.min(pos,result[i]);
        }
    }
    return result;
}

console.log(distance2('teachermode','e'));