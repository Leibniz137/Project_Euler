//problem21.js
//find the amicable numbers!

//amicable:
//d(n) = sum of n's proper divisors
//two numbers, a & b are amicable iff d(a) = b && d(b)=a

//brute force:


//d(n) dives the sum of the proper divisors of n
var d = function(n) {
    var d = 0;
    for (var i=1; i<n; ++i) {
        if (n%i==0) {
            d+=i;
        };
    };
    return d;
};

//memoization:
function dhash(n){
    dhash = new Object();
    for (var i=1; i<=n; ++i){
            dhash[i] = d(i);
        };
    return dhash;
};

function deletedoubles(amPairArray) {
    for (var i=1; i<(amPairArray.length); i+=2){
        delete amPairArray[i];
    };
    return amPairArray;
};


function amicablePairs(n){
    var dtable = dhash(n);
    var amPairs = new Array;
    for (var i=1; i<n; ++i) {
         for (var j=1; j<n; ++j) {
            if (i!=j){
                 if (dtable[i]==j && dtable[j]==i) {
                     amPairs.push([i,j].sort());
                 };   
             };
         };
     };
     return amPairs;
};


function amicablePairSum(amPairs){
    var sum = 0;
    for (var i=0; i<amPairs.length; i+=2){
        sum += (amPairs[i][0]+amPairs[i][1]);
    };
    return sum;
};


//print(amicablePairs(300)+"\n");

print(amicablePairSum(amicablePairs(10000))+"\n");








