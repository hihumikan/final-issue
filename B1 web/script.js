
function generateColorCode() {
  let randomColor = "#";
  for (var i = 0; i < 6; i++) {
    randomColor += ((16 * Math.random()) | 0).toString(16);
  }
  return randomColor;
}

const setupQuiz = function () {  //quizを解いたら次のquizをセットする関数
  document.getElementById("js-question").textContent = quiz[quizIndex].question;
  let buttonIndex = 0;
  let buttonLength = $button.length;
  while (buttonIndex < buttonLength) {
    $button[buttonIndex].textContent = quiz[quizIndex].answers[buttonIndex];
    buttonIndex++
  }
}

document.getElementById("firstButton").onclick = function () {
  var tmp1 = document.getElementById("ready");
  var tmp2 = document.getElementById("question");
  tmp1.className = "passive";
  tmp2.className = "active";
};

let alk = [1, 2, 3, 4];
let flag = 0;
var tmp = [];
const setupLevel = function () {
  let targetButton1 = document.getElementById("target-button-1");
  let targetButton2 = document.getElementById("target-button-2");
  let targetButton3 = document.getElementById("target-button-3");
  let targetButton4 = document.getElementById("target-button-4");
  let targetButton5 = document.getElementById("target-button-5");
  let targetButton6 = document.getElementById("target-button-6");
  let targetButton7 = document.getElementById("target-button-7");
  let targetButton8 = document.getElementById("target-button-8");

  targetButton1.style.backgroundColor = generateColorCode();
  tmp[1] = targetButton1.style.backgroundColor;
  targetButton2.style.backgroundColor = generateColorCode();
  tmp[2] = targetButton2.style.backgroundColor;
  targetButton3.style.backgroundColor = generateColorCode();
  tmp[3] = targetButton3.style.backgroundColor;
  targetButton4.style.backgroundColor = generateColorCode();
  tmp[4] = targetButton4.style.backgroundColor;

  targetButton5.style.backgroundColor = generateColorCode();
  tmp[5] = targetButton5.style.backgroundColor;
  targetButton6.style.backgroundColor = generateColorCode();
  tmp[6] = targetButton6.style.backgroundColor;
  targetButton7.style.backgroundColor = generateColorCode();
  tmp[7] = targetButton7.style.backgroundColor;
  targetButton8.style.backgroundColor = generateColorCode();
  tmp[8] = targetButton8.style.backgroundColor;
  
}
setupLevel();

var min = 1;
var max = 8;
var a="";
var elem="";
var counterCo=0;
var counterNo=0;
const randomED = function () {
  a = Math.floor(Math.random() * (max + 1 - min)) + min;
  elem = document.getElementById("test");
  elem.textContent = tmp[a];
  console.log(a);
  console.log(tmp[a]);
}
placeCounter1="";
placeCounter2="";
randomED();
placeCounter1= document.getElementById("Collect");
placeCounter2= document.getElementById("Nope");
var tmp11=document.getElementById("ara-toba-");
var tmp22=document.getElementById("ara-toba-2");
function msgDsp(e) {
  if (e == a) {
    setupLevel();
    randomED();
    counterCo++;
    placeCounter1.textContent = "正解数:"+counterCo;
    tmp11.className="active";
  } else {
    alert('不正解です！');
    counterNo++;
    placeCounter2.textContent = "間違えた数:"+counterNo;
    tmp22.className="active";
  }
}

