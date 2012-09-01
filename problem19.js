//problem19.js

//How many sundays fell on the first month in the 20th Century?

// 1/1/1900 was a monday

//jan:31
//feb: 28 ^ 29
//march: 31
//april: 30
//may:31
//june:30
//july:31
//august:31
//september:30
//october:31
//november:30
//december:31


    




//with sunday as first-day
function ayear(startdaynum,leapyear){
    var months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    var days = {sunday:0, monday:1, tuesday:2, wednesday:3, thursday:4, friday:5, saturday:6};
    if (leapyear) {months[1]=29};
    firstday=startdaynum;
    count=0;
    for (var i in months){
        if (firstday==0){
            count += 1;
        };
          firstday=(firstday+(months[i]%7))%7;
    };
    return count;
};


//print(ayear(0,true)+"\n");

function leapyear(year){
  if (year%400==0) {
    return true;
  }
  else if (year%100==0){
     return false;
   }
  else if (year%4==0){
     return true;
   }
  else{
     return false;
   }
};

function century(startyear){
  var suncount = 0;
  startdaynum = 1;
  for (var year=startyear; year<startyear+99; ++year){
    leap = leapyear(year);
    suncount+=ayear(startdaynum,leap);
    if (leap) {startdaynum = (startdaynum+2)%7}
    else {startdaynum = (startdaynum+1)%7}; 
  };
  print(year+"\n");
  return suncount;
};

print(century(1901)+"\n");


