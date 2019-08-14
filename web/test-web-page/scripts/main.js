//Changing H1 text
var myHeading = document.querySelector('h1');
myHeading.textContent = 'Привітульки!';


//Showing allert on start
var iceCream = 'chocolate';
if (iceCream === 'chocolate') {
    alert('Yay, I love chocolate ice cream!');
} else {
    alert('Awwww, but chocolate is my favorite...');
}

//Event when pressing body
document.querySelector('h1').onclick =
    function () {
        alert('Ouch! Stop poking me!');
    }

//Changing between images when pressing on it
var myImage = document.querySelector('img');
myImage.onclick = function () {
    var mySrc = myImage.getAttribute('src');
    if (mySrc === 'images/edge-of-space.jpg') {
        myImage.setAttribute('src', 'images/yellow-mushrooms.jpg');
        myImage.setAttribute('alt', 'Mashrooms with yellow head growing in forest.');
    }
    else {
        myImage.setAttribute('src', 'images/edge-of-space.jpg');
        myImage.setAttribute('alt', 'View from U-2 Bomber pilot cabine on edge of space.');
    }
}

//personlaization of H1 header
var myButton = document.querySelector('button');
var myHeading = document.querySelector('h1');

function setUserName() {
    var myName = prompt('Please enter your name.');
    localStorage.setItem('name', myName);
    myHeading.textContent = 'Mozzila is of course cool, but I just wanna say hello ' + myName;
}

if (!localStorage.getItem('name')) {
    setUserName();
} else {
    var storedName = localStorage.getItem('name');
    myHeading.textContent = 'Mozilla is cool, ' + storedName;
}

myButton.onclick = function () {
    setUserName();
}