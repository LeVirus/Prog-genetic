#include <sstream>
#include "Fenetre.hpp"
#include "constantes.hpp"

using namespace std;


Fenetre::Fenetre(Racine *a){
	 if(!a)return;
	 ptrRacine=a;
	 windowSF.create(sf::VideoMode(LARGEUR_FENETRE, LONGUEUR_FENETRE), "shoot", sf::Style::Default);
	 // MIN MAX PAS
	 spinNombreVille = sfg::SpinButton::Create( 5.f, 20.f, 1.f );
	 spinNbrIndSelect = sfg::SpinButton::Create( 4.f, 200.f, 2.f );
	 spinNombreIteration = sfg::SpinButton::Create( 1.f, 100.f, 1.f );
	 // taille du spinbox
	 spinNombreVille->SetRequisition( sf::Vector2f( 80.f, 0.f ) );
	 spinNbrIndSelect->SetRequisition( sf::Vector2f( 80.f, 0.f ) );
	 // Set the number of digits to display after the decimal point.
	 //spinNombreVille->SetDigits( 0 );
	 spinNombreInd = sfg::SpinButton::Create( 20.f, 500.f, 10.f );
	 // taille du spinbox
	 spinNombreInd->SetRequisition( sf::Vector2f( 80.f, 0.f ) );
	 // Set the number of digits to display after the decimal point.
	 //spinNombreInd->SetDigits( 0 );
	 combOpSelect = sfg::ComboBox::Create();
	 combOpSelect->AppendItem( "roulette" );
	 combOpSelect->AppendItem( "select par rang" );
	 combOpSelect->AppendItem( "tournoi" );
	 combOpSelect->PrependItem( "elitisme" );
	 
	 combOpReplace = sfg::ComboBox::Create();
	 combOpReplace->AppendItem( "Statique" );
	 combOpReplace->PrependItem( "Elitiste" );
	 
	 combModCroismnt = sfg::ComboBox::Create();
	 combModCroismnt->AppendItem( "Simple" );
	 combModCroismnt->PrependItem( "Complexe" );
	 
	 combModExec = sfg::ComboBox::Create();
	 combModExec->AppendItem( "Manuel" );
	 combModExec->PrependItem( "Nombre Iteration" );
	 //valeur par defaut
	 donnees.nbrVille=4;
	 donnees.nbrIndSelect=4;
	 donnees.nbrIndividu=10;
	 donnees.opSelect=0;
	 donnees.opReplace=0;
	 donnees.modeCroisement=0;
	 donnees.modeExec=0;
}

void Fenetre::gestionEvent(){
	 sf::Event event;
	 sf::Clock clock;
	 sfg::Box::Ptr box( sfg::Box::Create( sfg::Box::VERTICAL, 5.0f ) );
	 sfg::Window::Ptr windowSFG( sfg::Window::Create() );
	 sfg::Desktop desktop;
	 sfg::Label::Ptr labelA, labelB, labelC, labelD, labelE, labelF, labelG, labelH;
	 sfg::Button::Ptr buttonReset, buttonLaunch;
	 
	 
	 labelA = sfg::Label::Create( "Nombre Villes?" );
	 labelB = sfg::Label::Create( "Nombre Individus?" );
	 labelC = sfg::Label::Create( "Operateur de selection?" );
	 labelD = sfg::Label::Create( "Operateur de remplacement?" );
	 labelE = sfg::Label::Create( "mode de croisement?" );
	 labelF = sfg::Label::Create( "mode execution?" );
	 labelG = sfg::Label::Create( "Nombre individu a selectionner?" );
	 labelH = sfg::Label::Create( "Nombre Iteration?" );
	 
	 buttonReset = sfg::Button::Create( "RESET" );
	 buttonLaunch = sfg::Button::Create( "LAUNCH" );
	 
	 windowSF.setFramerateLimit(20);
	 
	 // Set the entries of the combo box.
	 
	 
	 
	 spinNombreVille->GetSignal( sfg::SpinButton::OnValueChanged ).Connect( &Fenetre::setNombreVille, this );
	 spinNombreInd->GetSignal( sfg::SpinButton::OnValueChanged ).Connect( &Fenetre::setNombreInd, this );
	 spinNombreIteration->GetSignal( sfg::SpinButton::OnValueChanged ).Connect( &Fenetre::setNombreIteration, this );
	 spinNbrIndSelect->GetSignal( sfg::SpinButton::OnValueChanged ).Connect( &Fenetre::setNombreIndSelect, this );
	 combOpSelect->GetSignal( sfg::ComboBox::OnSelect ).Connect( &Fenetre::chooseSelectionOperator, this );
	 combOpReplace->GetSignal( sfg::ComboBox::OnSelect ).Connect( &Fenetre::chooseReplaceOperator, this );
	 combModCroismnt->GetSignal( sfg::ComboBox::OnSelect ).Connect( &Fenetre::chooseModeCroisement, this );
	 combModExec->GetSignal( sfg::ComboBox::OnSelect ).Connect( &Fenetre::chooseModeExecution, this );
	 buttonReset->GetSignal( sfg::Widget::OnLeftClick ).Connect( &Fenetre::signalReset, this );
	 buttonLaunch->GetSignal( sfg::Widget::OnLeftClick ).Connect( &Fenetre::signalLaunch, this );

	 // Add the SpinButton to the box.
	 box->Pack( labelA );
	 box->Pack( spinNombreVille );
	 box->Pack( labelB );
	 box->Pack( spinNombreInd );
	 box->Pack( labelG );
	 box->Pack( spinNbrIndSelect );
	 box->Pack( labelC );
	 box->Pack( combOpSelect );
	 box->Pack( labelD );
	 box->Pack( combOpReplace );
	 box->Pack( labelE );
	 box->Pack( combModCroismnt );
	 box->Pack( labelF );
	 box->Pack( combModExec );
	 box->Pack( labelH );
	 box->Pack( spinNombreIteration );
	 box->Pack( buttonReset, false );
	 box->Pack( buttonLaunch, false );
	 
	 
	 spinNombreVille->SetValue( 4.f );
	 spinNbrIndSelect->SetValue( 4.f );
	 spinNombreInd->SetRange( 10.f , nombreMaxIndividus( donnees.nbrVille ) );
	 spinNbrIndSelect->SetRange( 4.f , nombreMaxIndividus( donnees.nbrVille ) );
	 windowSFG->SetTitle( "Fenetre" );
	 windowSFG->Add( box );
	 
	 desktop.Add( windowSFG );
	 
	 windowSF.resetGLStates();
	 
	while ( windowSF.isOpen() ){
		windowSF.clear(sf::Color::Black);
		//sf::Clock temps;
		//window.pollEvent(event);
		if (/* event.type == sf::Event::Closed  ||*/  sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ){
		  windowSF.close();
		  break;
		}
		while( windowSF.pollEvent( event ) ) {
		  desktop.HandleEvent( event );
		}
		desktop.Update( clock.restart().asSeconds() );
		// Rendering.
		//windowSF.clear(sf::Color::Black);
		sfgui.Display( windowSF );
		windowSF.display();
	}
}

void Fenetre::setNombreVille() {
	 donnees.nbrVille=spinNombreVille->GetValue ();
	 //cout<< donnees.nbrVille<<"   Ville"<<endl;
	 spinNombreInd->SetRange( 10.f , nombreMaxIndividus( donnees.nbrVille ) );
	 spinNbrIndSelect->SetRange( 4.f , nombreMaxIndividus( donnees.nbrVille ) );
	 //modifier tranche individu
}

void Fenetre::setNombreIndSelect(){
	 donnees.nbrIndSelect=spinNbrIndSelect->GetValue ();
	 //cout<< donnees.nbrVille<<"   Ville"<<endl;

}

void Fenetre::setNombreInd(){
	 donnees.nbrIndividu=spinNombreInd->GetValue ();
	 //cout<<donnees.nbrIndividu<<"   Individu"<<endl;
}

void Fenetre::setNombreIteration(){
	 donnees.nbrIteration=spinNombreIteration->GetValue ();
	 //cout<<donnees.nbrIndividu<<"   Individu"<<endl;
}
short Fenetre::nombreMaxIndividus(unsigned int nombreVille){
  for(unsigned int i=nombreVille-1;i>3;--i){
	 nombreVille*=i;
		if(nombreVille>14000)return 14000;
	}
  return nombreVille;
}

void Fenetre::chooseSelectionOperator(){
	 donnees.opSelect=combOpSelect->GetSelectedItem();
	 //cout<<donnees.opSelect<<"   operateur de selection"<<endl;
}

void Fenetre::chooseReplaceOperator(){
	 donnees.opReplace=combOpReplace->GetSelectedItem();
	 //cout<<donnees.opReplace<<"   operateur de remplacement"<<endl;
}

void Fenetre::chooseModeCroisement(){
	 donnees.modeCroisement=combModCroismnt->GetSelectedItem();
	 //cout<<donnees.modeCroisement<<"   Mode Croisement"<<endl;
}

void Fenetre::chooseModeExecution(){
	 donnees.modeExec=combModExec->GetSelectedItem();
	 //cout<<donnees.modeExec<<"   Mode execution"<<endl;
}

void Fenetre::signalReset(){
	 cout<<"reset"<<endl;
}

void Fenetre::signalLaunch(){
	 cout<<"launch"<<endl;
	 ptrRacine->launch(&donnees);
}


Fenetre::~Fenetre(){

}
