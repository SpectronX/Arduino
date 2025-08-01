# Morse Code Input with Arduino

---

## Introduction

In my exploration, I decided to use an Arduino to create Morse code equivalents for letters.

At the beginning, it was quite hectic and blurry, especially when it came to getting the code to work properly. I managed to gain solid ground on the basics, although there are still some perfections to be made.

For now, I’m focused on getting single letters through Morse input. Expanding this idea to form full words and sentences, would later be worked upon.

The current button state and last button state are introduced to allow us to switch between the HIGHs and LOWs of the pushbutton.  
This setup helps track exactly when the button is pressed, and by satisfying the condition inside the if statement, we can get the counter to work the way we want.  
It also ensures that if the button is pressed and held down for a long time, it would still have the same effect as just pressing it once.

In the code, I also defined a 1-second window for the user to press the button multiple times.  
Depending on the number of presses recorded within that window (tracked by the count variables), we can then decide whether the input is a dot or a dash.

---

## How the 1-Second Window is Created

Now, how do we create that 1-second window?  
That's where `currentMillis` and `previousMillis` come into play.

By defining an interval of **1000 milliseconds** (1 second), we check if the difference between the current time and the previously recorded time is greater than or equal to that interval.  
Once it is, the 1-second window closes and the system moves on.

With this setup, the user has 1 second to either input a dot or a dash, depending on the letter he or she wants to write out.

---

## Symbol Mapping Table

| Number of Presses | Symbol |
|:-----------------:|:------:|
| 1                 | . (dot) |
| 2                 | __ (dash) |

---

## Current Limitations

One thing I noticed is that the user must start inputting immediately after the Arduino starts.  
Otherwise, the system will move ahead without waiting, and the first character could be missed.

I plan to work on improving this: maybe by waiting for the first button press before starting the timer.

Feel free to reach out if you have suggestions on that.

---

