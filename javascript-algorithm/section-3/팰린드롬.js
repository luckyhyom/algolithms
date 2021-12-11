function palindrome(str) {
    let reg = /\w/g;
    let onlyword = str.match(reg).join('');
    let reverved = str.match(reg).reverse().join('');
    return onlyword === reverved
        ? 'YES'
        : 'NO'
}
function palindrome2(str) {
    str = str.toLowerCase().replace(/[^a-z]/g,'');
    return str === str.split('').reverse().join('')
        ? 'YES'
        : 'NO'
}

console.log(palindrome2('ab:~,.,.aba'));