<link rel="stylesheet" type="text/css" href="design.css" media="screen"/>
const typingSound = document.getElementById('typing-sound');
const text = document.querySelector('.text');

text.addEventListener('animationstart', () => {
  typingSound.currentTime = 0;
  typingSound.play();
});

text.addEventListener('animationend', () => {
  typingSound.pause();
});
setTimeout(myFunction, 2000); // waits for 2 seconds before executing myFunction
function myFunction() {
    // code to be executed after a delay
  }