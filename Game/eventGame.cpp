#include "eventGame.h"
#include "LevelChoice.h"
#include "button.h"
#include "ShapeRenderer.h"

EventFunctionsGame::EventFunctionsGame()
{
	soundBufferFon = new sf::SoundBuffer;
	if (!soundBufferFon->loadFromFile("Assets/Son/chill-drum-loop-6887.wav")) { 
		std::cout << "erreur de chargement du fichier" << std::endl; 
	}
	soundFon = new sf::Sound; 
	PlaySound();
}

EventFunctionsGame::~EventFunctionsGame()
{
	delete soundBufferFon;
	delete soundFon;
	soundFon = nullptr;
	soundBufferFon = nullptr;
}

void EventFunctionsGame::eventChangeColorButton(GameObject* buttonCheck, sf::Color colorChange) {
	Button* buttonCheckButton = buttonCheck->getComponent<Button>();
	ShapeRenderer* buttonCheckShape = buttonCheck->getComponent<ShapeRenderer>();

	buttonCheckButton->color = colorChange;
	buttonCheckShape->SetColor(colorChange);
}

bool EventFunctionsGame::eventCollisionMouseButton(GameObject* buttonCheck, sf::Vector2i mousePosition) {
	Button* buttonCheckButton = buttonCheck->getComponent<Button>();

	sf::Vector2f position(buttonCheckButton->position.x, buttonCheckButton->position.y);
	float hauteur = buttonCheckButton->Size.y;
	float largeur = buttonCheckButton->Size.x;
	sf::Vector2f ShapeStart(position.x - largeur / 2, position.y - hauteur / 2);
	sf::Vector2f ShapeEnd(ShapeStart.x + largeur, ShapeStart.y + hauteur);

	if (
		(mousePosition.x > ShapeStart.x) && (mousePosition.x < ShapeEnd.x) &&
		(mousePosition.y > ShapeStart.y) && (mousePosition.y < ShapeEnd.y)
		)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void EventFunctionsGame::eventHoverButton(GameObject* buttonCheck, sf::Vector2i mousePosition) {
	Button* buttonCheckButton = buttonCheck->getComponent<Button>();

	if (eventCollisionMouseButton(buttonCheck, mousePosition) == true)
	{
		eventChangeColorButton(buttonCheck, buttonCheckButton->colorHover);
	}
	else
	{
		eventChangeColorButton(buttonCheck, buttonCheckButton->colorNothing);
	}

}

bool EventFunctionsGame::eventCheckClickButton(sf::Vector2i mousePosition, sf::Event event, sf::RenderWindow* window) {
	std::vector<std::string> returnWhat;

	for (GameObject* buttonCheck : buttonList)
	{
		returnWhat.push_back(eventClickButton(buttonCheck, mousePosition));
	}

	for (std::string returnWhatBool : returnWhat)
	{
		if (returnWhatBool == "Pause") {
			return true;
		}
	}
	return false;
}

std::string EventFunctionsGame::eventClickButton(GameObject* buttonCheck, sf::Vector2i mousePosition) {
	Button* buttonCheckButton = buttonCheck->getComponent<Button>();

	if (eventCollisionMouseButton(buttonCheck, mousePosition) == true)
	{
		eventChangeColorButton(buttonCheck, buttonCheckButton->colorClick);
		return buttonCheckButton->type;
	}
	return "";
}

void EventFunctionsGame::eventCloseWindow(sf::RenderWindow* window) {
	window->close();
}

void EventFunctionsGame::eventKeyPressed(sf::Event event) {
	for (Input* input : inputList)
	{
		if (input->inputType == Input::Keyboard && input->key == event.key.code)
		{
			input->inputBool = true;
		}
	}
}

void EventFunctionsGame::eventKeyReleased(sf::Event event) {
	for (Input* input : inputList)
	{
		if (input->inputType == Input::Keyboard && input->key == event.key.code)
		{
			input->inputBool = false;
		}
	}
}

void EventFunctionsGame::angleWrite(float AngleMouseHor) {
	if (AngleMouseHor > 30 && AngleMouseHor <= 60)
	{
		std::cout << "Right" << std::endl << std::endl;
	}
	else if (AngleMouseHor > 60 && AngleMouseHor <= 120)
	{
		std::cout << std::endl << std::endl;
	}
	else if (AngleMouseHor > 120 && AngleMouseHor <= 150)
	{
		std::cout << "Left" << std::endl << std::endl;
	}
}

void EventFunctionsGame::eventMouseRight(sf::Event event, GameObject* actor, sf::RenderWindow* window, const Maths::Vector2f HorizontalOrigin, const Maths::Vector2f VerticalOrigin) {
	if (event.mouseButton.button == sf::Mouse::Right) {

		sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);

		Maths::Vector2f mousePositionVec(mousePosition.x, mousePosition.y);
		Maths::Vector2f VectorPlayerMouse = mousePositionVec - actor->GetPosition();

		float AngleMouseHor = VectorPlayerMouse.Angle(HorizontalOrigin);
		float AngleMouseVer = VectorPlayerMouse.Angle(VerticalOrigin);

		std::cout << "Clic : " << mousePosition.x << ", " << mousePosition.y << std::endl;
		std::cout << "Magnitude : " << VectorPlayerMouse.Magnitude() << std::endl;
		std::cout << "Angle Horizontal : " << AngleMouseHor << std::endl;
		std::cout << "Angle Veritical : " << AngleMouseVer << std::endl;
		std::cout << "Facing : ";

		if (AngleMouseHor <= 30)
		{
			std::cout << "Right" << std::endl << std::endl;
		}
		else if (AngleMouseHor > 150)
		{
			std::cout << "Left" << std::endl << std::endl;
		}
		else if (AngleMouseVer > 90)
		{
			std::cout << "Up";
			angleWrite(AngleMouseHor);
		}
		else if (AngleMouseVer <= 90)
		{
			std::cout << "Down";
			angleWrite(AngleMouseHor);
		}
	}
}

bool EventFunctionsGame::eventMouseLeft(sf::Event event, GameObject* actor, sf::RenderWindow* window, Scene* scene, float deltaTimeMilliseconds, sf::Vector2i mousePosition)
{
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		if (eventCheckClickButton(mousePosition, event, window))
		{
			return true;
		}

		sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);

		Maths::Vector2f mousePositionVec(mousePosition.x, mousePosition.y);
		Maths::Vector2f VectorPlayerMouse = mousePositionVec - actor->GetPosition();
		GameObject* bullet = scene->CreateBulletGameObject(ObjectName::BulletName, actor->GetPosition(), deltaTimeMilliseconds, sf::Color::Blue, VectorPlayerMouse, actor);

		return false;
	}
	return false;
}


bool EventFunctionsGame::eventMousePressed(sf::Event event, GameObject* actor, sf::RenderWindow* window, const Maths::Vector2f HorizontalOrigin, const Maths::Vector2f VerticalOrigin, Scene* scene, float deltaTimeMilliseconds, sf::Vector2i mousePosition) {
	//for (Input* input : inputList)
	//{
	//	if (input->inputType == Input::Mouse && input->mouseButton == event.mouseButton.button)
	//	{
	//		input->inputBool = true;
	//	}
	//}
	eventMouseRight(event, actor, window, HorizontalOrigin, VerticalOrigin);
	return eventMouseLeft(event, actor, window, scene, deltaTimeMilliseconds, mousePosition);
}

void EventFunctionsGame::eventMouseRelease(sf::Event event)  {
	if (event.mouseButton.button == sf::Mouse::Left) {
		// Parcourir les entr�es du souris
		for (Input* input : inputList)
		{
			if (input->inputType == Input::Mouse && input->mouseButton == event.mouseButton.button)
			{
				input->inputBool = false;
			}
		}
	}
}

void EventFunctionsGame::eventExecute(GameObject* actor, float sizeActor, sf::RenderWindow* window, std::vector<GameObject*>*gameObjects) {
	for (Input* input : inputList)
	{
		if (input->inputBool)
		{
			input->execute(actor, sizeActor, window, gameObjects);
		}
	}
}

std::vector<Input*> EventFunctionsGame::createVectorInput() {

	std::vector<Input*> inputListCreation;

	// Remplir le vecteur avec les entr�es d�sir�es
	inputListCreation.push_back(new DeplacementUp());
	inputListCreation.push_back(new DeplacementDown());
	inputListCreation.push_back(new DeplacementLeft());
	inputListCreation.push_back(new DeplacementRight());
	inputListCreation.push_back(new Shoot());

	return inputListCreation;
}

void EventFunctionsGame::PlaySound()
{
	soundFon->setBuffer(*soundBufferFon);
	soundFon->play();
}



bool EventFunctionsGame::loopEvent(GameObject* actor, float sizeActor, sf::RenderWindow* window, const Maths::Vector2f HorizontalOrigin, const Maths::Vector2f VerticalOrigin, Scene* scene, float deltaTimeMilliseconds, bool *pauseOn) {
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
	eventHoverButton(buttonList[0], mousePosition);

	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			eventCloseWindow(window);
			return false;
		}


		else if (event.type == sf::Event::KeyPressed) {
			eventKeyPressed(event);
			actor->getComponent<Player>()->PlaySound();
		}

		else if (event.type == sf::Event::KeyReleased) {
			eventKeyReleased(event);
			actor->getComponent<Player>()->StopSound();
		}

		else if (event.type == sf::Event::MouseButtonPressed) {
			*pauseOn = eventMousePressed(event, actor, window, HorizontalOrigin, VerticalOrigin, scene, deltaTimeMilliseconds, mousePosition);
		}

		else if (event.type == sf::Event::MouseButtonReleased) {
			eventMouseRelease(event);
		}
	}


	// Parcourir les entr�es du souris
	eventExecute(actor, sizeActor, window, scene->GetGameObjects());
	return true;
}