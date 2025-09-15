public class KpopGuitarMan {

    int position_x;
    int position_y;
    int mouth_size;

    color clothes_color;
    color pants_color;
    color guitar_color;

    public KpopGuitarMan() {
        position_x = (int)random(-200, width-400);
        position_y = (int)random(-50, height-630);
        clothes_color = color(random(0, 256), random(0, 256), random(0, 256));
        pants_color = color(random(0, 256), random(0, 256), random(0, 256));
        guitar_color = color(random(0, 256), random(0, 256), random(0, 256));
        mouth_size = (int)random(-5, 200);
    }

    public void drawKpopGuitarMan() {
        pushMatrix();
        
        translate(position_x, position_y);
        drawHead();
        drawBody();

        popMatrix();
    }

    // A function that is responsible for the overall part of the head.
    private void drawHead() {
        fill(#FFE5B4); // the color of overall skin is apricot.
        noStroke();
        ellipseMode(CENTER);
        ellipse(400, 150, 120, 150);
        
        drawEyes();
        drawNose();
        drawNeck(); // if mouth is bigger and bigger, it can invade the neck. so i will draw
                    // the neck first and then draw the mouth.
        drawMouth();
        drawHair();
    }

    // A function of drawing eyes.
    private void drawEyes() {
        // drawing white eyes.
        stroke(0);
        fill(255);
        ellipse(375, 127, 15, 15);
        ellipse(425, 127, 15, 15);

        // drawing black pupils inside eyes. pupils have little transparency
        stroke(0);
        fill(0, 200);
        ellipse(375, 127, 7, 7);
        ellipse(425, 127, 7, 7);
    }

    // A function of drawing a nose.
    private void drawNose() {
        // drawing total nose.
        stroke(0);
        fill(#fbceb1);
        triangle(400, 135, 390, 170, 410, 170);

        // drawing nostrils.
        noStroke();
        fill(0);
        ellipse(397, 168, 5, 5);
        ellipse(403, 168, 5, 5);
    }

    

    // A function of drawing a mouth.
    private void drawMouth() {
        // drawing stoke as lips. The color of lips is pink.
        pushStyle();
        strokeWeight(3);
        stroke(#ffc0cb);
        

        // drawing the mouth. The color of mouth is dark red.
        // the part that is inside the mouth has little transparency.
        fill(#861938, 180);
        bezier(400, 190 - 0.2 * mouth_size, 450 + mouth_size, 170 - 0.2 * mouth_size, 450 + mouth_size, 200 + 0.2 * mouth_size, 400, 210 + 0.2 * mouth_size);
        bezier(400, 190 - 0.2 * mouth_size, 350 - mouth_size, 170 - 0.2 * mouth_size, 350 - mouth_size, 200 + 0.2 * mouth_size, 400, 210 + 0.2 * mouth_size);
        popStyle();
    }

    private void drawNeck() {
        // drawing neck.
        stroke(#FFE5B4);
        fill(#FFE5B4);
        rect(380, 220, 40, 30);
    }

    // A function of drawing hair.
    private void drawHair() {
        // the color of hair is yellow.
        stroke(#FFD400);
        fill(#FFD400);

        bezier(355, 100, 355, 70, 445, 70, 445, 100);
        triangle(380, 80, 400, 30, 420, 80);
        triangle(380, 80, 355, 97, 340, 40);
        triangle(460, 40, 420, 80, 445, 97);

        // making hair naturally to fit the shape of head.
        stroke(#FFE5B4);
        fill(#FFE5B4);
        bezier(355, 100, 355, 85, 445, 85, 445, 100);
    }

    // A function that is responsible for the overall part of the body.
    private void drawBody() {
        // drawing torso.
        noStroke();
        fill(clothes_color);
        rect(350, 250, 100, 200);

        // making clothes part naturally between neck and torso.
        stroke(#FFE5B4);
        fill(#FFE5B4);
        arc(400, 245, 40, 40, 0, PI);

        drawLeftArm();
        drawGuitar();
        drawLeftHand();
        drawRightArm_Hand();
        drawLegs();
    }

    private void drawLeftArm() {
        // drawing right arm first because it frets the chords.
        noStroke();
        fill(#FFE5B4);
        quad(350, 250, 350, 290, 270, 410, 232, 410);
    }

    private void drawGuitar() {
        // drawing frets.
        stroke(0);
        fill(guitar_color);
        rect(180, 410, 300, 30);

        // drawing guitar strings.
        fill(0);
        pushStyle();
        strokeWeight(2);
        popStyle();
        for(int i = 1; i <= 6; i++) {
            line(180, 408 + 5 * i, 480, 408 + 5 * i);
        }

        // draw guitar body.
        stroke(0);
        fill(guitar_color);
        beginShape();
        vertex(480, 410);
        vertex(650, 350);
        vertex(620, 425);
        vertex(650, 500);
        vertex(480, 440);
        endShape(CLOSE);

        stroke(0);
        fill(255);
        rect(520, 410, 10, 30);
        rect(580, 410, 10, 30);
        
        for(int i = 1; i <= 6; i++) {
            ellipse(585, 408 + 5 * i, 1, 1);
            line(480, 408 + 5 * i, 585, 408 + 5 * i);
        }

        //drawing guitar neck.
        stroke(0);
        fill(guitar_color);
        beginShape();
        vertex(180, 410);
        vertex(70, 390);
        vertex(135, 455);
        vertex(180, 440);
        endShape(CLOSE);

        noStroke();
        fill(255);
        for(int i = 1; i <= 6; i++) {
            ellipse(100 + 5 * i, 408 + 5 * i, 3, 3);
        }
        stroke(2);
        for(int i = 1; i <= 6; i++) {
            line(100 + 5 * i, 408 + 5 * i, 180, 408 + 5 * i);
        }
    }

    private void drawLeftHand() {
        fill(#FFE5B4);
        stroke(#FFE5B4);

        // drawing fingers.
        ellipse(225, 425, 5, 39);
        ellipse(232, 435, 5, 23);
        ellipse(239, 436, 5, 18);
        ellipse(247, 439, 5, 13);
        
        arc(236, 440, 25, 25, 0, PI);
    }

    private void drawRightArm_Hand() {
        // drawing right arm.
        noStroke();
        fill(#FFE5B4);
        quad(450, 252, 450, 290, 540, 330, 575, 330);
        quad(540, 330, 575, 330, 560, 400, 534, 396);

        // drawing right hand.
        ellipse(547, 398, 28, 28);
        ellipse(534, 396, 20, 5);
        ellipse(535, 410, 5, 25);
        ellipse(542, 410, 5, 33);
        ellipse(550, 410, 5, 27);
        ellipse(558, 409, 5, 13);
    }

    private void drawLegs() {
        noStroke();
        fill(pants_color);

        beginShape();
        vertex(350, 450);
        vertex(300, 650);
        vertex(350, 650);
        vertex(400, 460);
        vertex(450, 650);
        vertex(500, 650);
        vertex(450, 450);
        endShape(CLOSE);

        pushStyle();
        strokeWeight(2);
        stroke(#020715);
        fill(255);
        bezier(300, 650, 270, 650, 270, 670, 300, 670);
        
        line(300, 670, 350, 670);
        line(350, 670, 350, 650);
        line(350, 650, 300, 650);
        
        bezier(500, 650, 530, 650, 530, 670, 500, 670);
        line(500, 670, 450, 670);
        line(450, 670, 450, 650);
        line(450, 650, 500, 650);
        popStyle();
    }

}

KpopGuitarMan guitarMan = null;

void setup() {
    size(1000, 700);
    background(50);
}

void draw() {
    background(50);
    if(guitarMan != null) {
        guitarMan.drawKpopGuitarMan();
    }
}

void keyPressed() {
    if(key == 's' || key == 'S') {
        guitarMan = new KpopGuitarMan();
    }

    if(key == 'd' || key == 'D') {
        guitarMan = null;
    }
}