var myHeading = document.querySelector('h1');
myHeading.textContent = 'Привітульки!';

var iceCream = 'chocolate';
if (iceCream === 'chocolate') {
  alert('Yay, I love chocolate ice cream!');    
} else {
  alert('Awwww, but chocolate is my favorite...');    
}

document.querySelector('body').onclick = function() {
    alert('Ouch! Stop poking me!');
}