void setup() {
  size(800, 700);
  background(255);
}

// A function that is responsible for the overall part of the head.
void drawHead() {
  fill(#FFE5B4); // the color of overall skin is apricot.
  noStroke();
  ellipseMode(CENTER);
  ellipse(400, 150, 120, 150);
  
  drawEyes();
  drawNose();
  drawMouth();
  drawHair();
}

// A function of drawing eyes.
void drawEyes() {
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
void drawNose() {
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
void drawMouth() {
  // drawing stoke as lips. The color of lips is pink.
  pushStyle();
  strokeWeight(3);
  stroke(#ffc0cb);

  // drawing the mouth. The color of mouth is dark red.
  // the part that is inside the mouth has little transparency.
  fill(#861938, 180);
  bezier(400, 190, 450, 170, 450, 200, 400, 210);
  bezier(400, 190, 350, 170, 350, 200, 400, 210);
  popStyle();
}

// A function of drawing hair.
void drawHair() {
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
void drawBody() {
  // drawing neck.
  stroke(#FFE5B4);
  fill(#FFE5B4);
  rect(380, 220, 40, 30);

  // drawing torso.
  noStroke();
  fill(#000080);
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

// A function of drawing left arm.
void drawLeftArm() {
  // drawing right arm first because it frets the chords.
  noStroke();
  fill(#FFE5B4);
  quad(350, 250, 350, 290, 270, 410, 232, 410);
}

// A function of drawing guitar.
void drawGuitar() {
  // drawing frets.
  stroke(0);
  fill(#212121);
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
  fill(#212121);
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
  fill(#212121);
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

// A function of drawing left hand.
void drawLeftHand() {
  fill(#FFE5B4);
  stroke(#FFE5B4);

  // drawing fingers.
  ellipse(225, 425, 5, 39);
  ellipse(232, 435, 5, 23);
  ellipse(239, 436, 5, 18);
  ellipse(247, 439, 5, 13);
  
  arc(236, 440, 25, 25, 0, PI);
}

// A function of drawing right arm and right hand.
void drawRightArm_Hand() {
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

// A funtion of drawing legs.
void drawLegs() {
  // drawing legs.
  noStroke();
  fill(#9CBCFF);

  beginShape();
  vertex(350, 450);
  vertex(300, 650);
  vertex(350, 650);
  vertex(400, 460);
  vertex(450, 650);
  vertex(500, 650);
  vertex(450, 450);
  endShape(CLOSE);

  // drawing sneakers.
  pushStyle();

  fill(#7B1113);
  stroke(#654321);      
  strokeWeight(3);
  
  beginShape();
  vertex(300, 650);                             
  bezierVertex(270, 650, 270, 670, 300, 670);    
  vertex(350, 670);                              
  vertex(350, 650);                              
  endShape(CLOSE);                               
  
  beginShape();
  vertex(500, 650);                              
  vertex(450, 650);                              
  vertex(450, 670);                              
  vertex(500, 670);                              
  bezierVertex(530, 670, 530, 650, 500, 650);    
  endShape();

  popStyle();
}

void draw() {
  drawHead();
  drawBody();
}