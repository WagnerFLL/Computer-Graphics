//
// Created by lucas on 3/31/2019.
//

#ifndef COMPUTER_GRAPHICS_DRAWWALL_H
#define COMPUTER_GRAPHICS_DRAWWALL_H

void drawOrthoWall(float x, float z, float width, int floor) {
	float relativeX = x + width / 2;
	float relativeY = 1.75 + (floor * (3.5 + floor2_thickness)) + wall_height + floor1_height;

	glPushMatrix();
	glTranslatef(relativeX, relativeY, z);
	glColor3f(0.7f, 0.7f, 0.7f);
	glScalef(width, 3.5, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	textureWall(x, z + 0.05, width, floor, 0);
	textureWall(x, z - 0.06, width, floor, 0);
}

void drawParallelWall(float x, float z, float width, int floor) {
	float relativeZ = z + width / 2;
	float relativeY = 1.75 + (floor * (3.5 + floor2_thickness))
					  + wall_height + floor1_height;

	glPushMatrix();
	glTranslatef(x, relativeY, relativeZ);
	glRotatef(90, 0, 1, 0);
	glColor3f(0.7f, 0.7f, 0.7f);
	glScalef(width, 3.5, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	textureWall(x + 0.06, width + z, width, floor, 1);
	textureWall(x - 0.06, width + z, width, floor, 1);

}

void drawDoorOrtho(float x, float z, float floor) {
	float doorWidth = 1.25;
	float doorHeight = 2.2;
	float relativeX = x + (doorWidth / 2);
	float relativeY = doorHeight / 2
					  + (floor * (3.5 + floor2_thickness))
					  + wall_height + floor1_height;

	glPushMatrix();
	glTranslatef(relativeX + ((doorWidth / 2) * -1), relativeY, z);
	glRotatef(door_angle, 0, 1, 0);
	glTranslatef((doorWidth / 2), 0, 0);
	glColor3f(0.5f, 0.25f, 0.0);
	glScalef(doorWidth, doorHeight, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();
}

void drawDoorParallel(float x, float z, float floor) {
	float doorWidth = 1.25;
	float doorHeight = 2.2;
	float relativeZ = z + (doorWidth / 2);
	float relativeY = doorHeight / 2
					  + (floor * (3.5 + floor2_thickness))
					  + wall_height + floor1_height;

	glPushMatrix();
	glTranslatef(x, relativeY, relativeZ + ((doorWidth / 2) * -1));
	glRotatef(door_angle, 0, 1, 0);
	glTranslatef(0, 0, (doorWidth / 2));
	glRotatef(90, 0, 1, 0);
	glColor3f(0.5f, 0.25f, 0.0);
	glScalef(doorWidth, doorHeight, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();
}

void drawOrthoWallWithDoor(float x, float z, float width, int floor, float doorLocation) {
	float doorHeight = 2.2;
	float doorWidth = 1.25;

	float newWidth = (width / 2) - (doorWidth / 2);
	float width1 = newWidth * doorLocation;
	float width2 = newWidth * (2 - doorLocation);
	float x1 = x;
	float z1 = z;
	float x2 = x + width1 + doorWidth;
	float z2 = z;

	drawOrthoWall(x1, z1, width1, floor); // parede a esquerda da porta
	drawOrthoWall(x2, z2, width2, floor); // parede a direita da porta

	float relativeX = x + width1 + doorWidth / 2; // parede emcima da porta
	float relativeY = 3.5 - ((3.5 - doorHeight) / 2)
					  + (floor * (3.5 + floor2_thickness))
					  + wall_height + floor1_height;

	glPushMatrix();
	glTranslatef(relativeX, relativeY, z);
	glColor3f(0.7f, 0.7f, 0.7f);
	glScalef(doorWidth, 3.5 - doorHeight, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	drawDoorOrtho(x + width1, z, floor);
}

void drawParallelWallWithDoor(float x, float z, float width, int floor, float doorLocation) {
	float doorHeight = 2.2;
	float doorWidth = 1.25;

	float newWidth = (width / 2) - (doorWidth / 2);
	float width1 = newWidth * doorLocation;
	float width2 = newWidth * (2 - doorLocation);
	float x1 = x;
	float z1 = z;
	float x2 = x;
	float z2 = z + width1 + doorWidth;

	drawParallelWall(x1, z1, width1, floor); // parede a esquerda da porta
	drawParallelWall(x2, z2, width2, floor); // parede a direita da porta

	float relativeZ = z + width1 + doorWidth / 2; // parede emcima da porta
	float relativeY = 3.5 - ((3.5 - doorHeight) / 2)
					  + (floor * (3.5 + floor2_thickness))
					  + wall_height + floor1_height;

	glPushMatrix();
	glTranslatef(x, relativeY, relativeZ);
	glRotatef(90, 0, 1, 0);
	glColor3f(0.7f, 0.7f, 0.7f);
	glScalef(doorWidth, 3.5 - doorHeight, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	drawDoorParallel(x, z + width1, floor);
}

#endif //COMPUTER_GRAPHICS_DRAWWALL_H