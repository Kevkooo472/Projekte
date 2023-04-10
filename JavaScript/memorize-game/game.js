
let buttonColours = ["red", "blue", "green", "yellow"];
let started = false;
let level = 0;
let gamePattern = [];
let userPattern = [];

$(document).keypress(function (){
    if (!started) {
        $("#level-title").text("Level " + level);
        nextSequence();
        started = true;
    }
});

$(".btn").click(function () {
    let chosenColour = $(this).attr("id");
    userPattern.push(chosenColour);
    checkAnswer(userPattern.length - 1);
    playSound(chosenColour);
    animatePress(chosenColour);
});

function nextSequence() {
    userPattern = [];
    level++;
    $("#level-title").text("Level " + level);
    let randNum = Math.ceil(Math.random() * 4) - 1;
    let randColour = buttonColours[randNum];
    gamePattern.push(randColour);
    $("#" + randColour).fadeIn(100).fadeOut(100).fadeIn(100);
    playSound(randColour);
}

function checkAnswer(currentLevel) {
    if (userPattern[currentLevel] === gamePattern[currentLevel]) {
        if (userPattern.length === gamePattern.length) {
            setTimeout(function () {
                nextSequence();
            }, 1000);
        }
    } else {
        playSound("wrong");
        $("body").addClass("game-over");
        setTimeout(function () {
            $("body").removeClass("game-over");
        }, 200);
        $("#level-title").text("Game over - Drücke beliebige Taste um neuzustarten.");
        startOver();
    }
}

function playSound(name) {
    var r_audio = new Audio("sounds/" + name + ".mp3");
    r_audio.play();
}

function animatePress(currentColour) {
    $("#" + currentColour).addClass("pressed");
    setTimeout(function () {
        $("#" + currentColour).removeClass("pressed");
    }, 100);
}

function startOver() {
    level = 0;
    started = false;
    gamePattern = [];
}