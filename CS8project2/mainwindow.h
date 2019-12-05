/***************************************
 * AUTHOR                : Justin Kuhn, Anna Ma, Kevin Prada
 * Project 2             : I Love Baseball
 * CLASS                 : CS8
 * SECTION               : MW 9:45-11:10AM TTH 9:45-11:50AM
 * Due Date              : 12/5/19
 * *************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "graph.h"
#include "souvenir.h"
#include <QMainWindow>
#include <QMessageBox>
#include <vector>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


/*******************************************************************
 *  userInfo struct
 *     This contains a unique instance info for a user.
 * *****************************************************************/
struct userInfo
{
    List<stadiumNode> plannedTrips;     //ATT - all trips
    souvenirs souvenirList;             //ATT - assoc. souvenirs
};

/*******************************************************************
 *  MainWindow Class
 *     This class represents a the graphical aspect of the user interface
 *       Mananges graph, souvenir, UserInfo, dreamList, and *ui attributes
 *
 * *****************************************************************/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //Function that changes tab of StackedWidget to index passed in

    /*******************************************************************
     *  void gotoPage(int pg);
     *     This goes to the passed page
     * *****************************************************************/
    void gotoPage(int pg);      //IN - page to switch to

private slots:
    /*******************************************************************
     *  void on_exitMainButton_clicked();
     *     Exits the program
     * *****************************************************************/
    void on_exitMainButton_clicked();

    /*******************************************************************
     *  void on_customerPushButtonMenu_clicked();
     *     Go to the customer page.
     * *****************************************************************/
    void on_customerPushButtonMenu_clicked();

    /*******************************************************************
     *  void on_customerDoneButton_clicked();
     *     get out of customer page.
     * *****************************************************************/
    void on_customerDoneButton_clicked();

    /*******************************************************************
     *  void on_mapPgDoneButton_clicked();
     *     get out of map page
     * *****************************************************************/
    void on_mapPgDoneButton_clicked();

    /*******************************************************************
     *   void on_adminPgDoneButton_clicked();
     *     get out of admin page
     * *****************************************************************/
    void on_adminPgDoneButton_clicked();
    /*******************************************************************
     *  void on_adminPushButtonMain_clicked();
     *     get into admin page
     * *****************************************************************/
    void on_adminPushButtonMain_clicked();

    /*******************************************************************
     *  void on_souvenirsDoneButton_clicked();
     *     get into souvenirs page
     * *****************************************************************/
    void on_souvenirsDoneButton_clicked();


    /*******************************************************************
     *  void on_stadiumInfoDoneButton_clicked();
     *     display info for selected stadium
     * *****************************************************************/
    void on_stadiumInfoDoneButton_clicked();


    /*******************************************************************
     *  void setStadiumTextBrowser(string stadiumTemp);
     *     set the text in the text browser
     * *****************************************************************/
    void setStadiumTextBrowser(string stadiumTemp); //IN - stadium to add


    /*******************************************************************
     *  void on_stadiumsByNamButton_clicked();
     *     sort stadiums by name
     * *****************************************************************/
    void on_stadiumsByNamButton_clicked();

    /*******************************************************************
     *  void on_stadiumTableInfo_clicked();
     *     display stadium info
     * *****************************************************************/
    void on_stadiumTableInfo_clicked();


    /*******************************************************************
     *  void on_GrassSurface_currentIndexChanged();
     *     change index of fields in list with grass surfaces
     * *****************************************************************/
    void on_GrassSurface_currentIndexChanged();



    /*******************************************************************
     *  void on_planTripButton_clicked();
     *     button to plan trip
     * *****************************************************************/
    void on_planTripButton_clicked();

    /*******************************************************************
     *  void on_pushButton_31_clicked();
     *     unknown function
     * *****************************************************************/
    void on_pushButton_31_clicked();


    /*******************************************************************
     *  void on_allStadiumsButton_clicked();
     *     select all stadiums
     * *****************************************************************/
    void on_allStadiumsButton_clicked();

    /*******************************************************************
     *  void on_pushButton_38_clicked();
     *     unknown function
     * *****************************************************************/
    void on_pushButton_38_clicked();

    /*******************************************************************
     *  void on_pushButton_39_clicked();
     *     unknown function
     * *****************************************************************/
    void on_pushButton_39_clicked();

    /*******************************************************************
     *  void on_pushButton_clicked();
     *     unknown function
     * *****************************************************************/
    void on_pushButton_clicked();

    /*******************************************************************
     *  void on_pushButton_3_clicked();
     *     unknown function
     * *****************************************************************/
    void on_pushButton_3_clicked();

    /*******************************************************************
     *  void on_modAddNewButton_clicked()
     *     button to add a new stadium
     * *****************************************************************/
    void on_modAddNewButton_clicked();

    /*******************************************************************
     *  void on_modSDoneButton_clicked();
     *     if admin is done adding new souvenirs
     * *****************************************************************/
    void on_modSDoneButton_clicked();

    /*******************************************************************
     *  void on_modSAddNewButton_clicked();
     *     admin can add new souvenirs with this button.
     * *****************************************************************/
    void on_modSAddNewButton_clicked();


    /*******************************************************************
     *  void on_modDoneButton_clicked();
     *     admin is dont modifying items.
     * *****************************************************************/
    void on_modDoneButton_clicked();

    /*******************************************************************
     *  void on_gobacktomainpage_clicked();
     *     takes back to main page
     * *****************************************************************/
    void on_gobacktomainpage_clicked();

    /*******************************************************************
     *   void on_stadiumTable_clicked();
     *     click button to reach stadium table
     * *****************************************************************/
    void on_stadiumTable_clicked();



    /*******************************************************************
     *  void planTeamButtons(string stadiumName);
     *     add the name of the selected team to the trip planner
     * *****************************************************************/
    void planTeamButtons(string stadiumName);


    /*******************************************************************
     *  void on_stadiumInfoCheckBox_stateChanged(int arg1);
     *     check box to display stadium info
     * *****************************************************************/
    void on_stadiumInfoCheckBox_stateChanged(int arg1); //IN - *placehold*

    /*******************************************************************
     *  void on_sanDiegoButton_clicked();
     *     check box to display stadium info
     * *****************************************************************/

    // ALL of the below buttons have similar function
    // They add the intended stadium to the planning page
    void on_sanDiegoButton_clicked();

    void on_dodgerButton_clicked();

    void on_kansasCityButton_clicked();

    void on_stLouisButton_clicked();

    void on_nyMetsButton_clicked();

    void on_sanFranciscoButton_clicked();

    void on_oaklandAButton_clicked();

    void on_seattleButton_clicked();

    void on_coloradoButton_clicked();

    void on_angelsButton_clicked();

    void on_arizonaButton_clicked();

    void on_minnesotaButton_clicked();

    void on_texasRangersButton_clicked();

    void on_houstonButton_clicked();

    void on_milwaukeeButton_clicked();

    void on_chicagoButton_clicked();

    void on_chicagoWhiteSoxButton_clicked();

    void on_cincinattiButton_clicked();

    void on_atlantaButton_clicked();

    void on_clevelandButton_clicked();

    void on_tampaBayButton_clicked();

    void on_floridaButton_clicked();

    void on_pittsburghButton_clicked();

    void on_washingtonButton_clicked();

    void on_torontoButton_clicked();

    void on_detroitButton_2_clicked();

    void on_bostonButton_clicked();

    void on_baltimoreButton_clicked();

    void on_phillyButton_clicked();

    void on_nyYankeesButton_clicked();

    /*******************************************************************/

    /*******************************************************************
     *  void on_restartDreamList_clicked();
     *     reset list of stadiums
     * *****************************************************************/
    void on_restartDreamList_clicked();

    /*******************************************************************
     *  void on_allNLStadiumsButton_clicked();
     *     select all national league stadiums
     * *****************************************************************/
    void on_allNLStadiumsButton_clicked();

    /*******************************************************************
     *  void on_allALStadiumsButton_clicked();
     *     select all American League stadiums
     * *****************************************************************/
    void on_allALStadiumsButton_clicked();

    /*******************************************************************
     *   void on_backtoMain_clicked();
     *     go back to the main page
     * *****************************************************************/
    void on_backtoMain_clicked();

    /*******************************************************************
     *  void on_showMapButton_clicked();
     *     show map from planning page
     * *****************************************************************/
    void on_showMapButton_clicked();

    /*******************************************************************
     *  void plannedTripTable();
     *     show table with planned trips
     * *****************************************************************/
    void plannedTripTable();

    List<stadium> modify_newStadiumAddedByUser(List<stadium> list);

    bool isNewStadium(stadium);

    void on_pushButton_5_clicked();

    void on_CancelButtonTrackSouvenir_clicked();

    void on_AddbuttonTrackSouvenir_clicked();

    void on_showMapButtonMainPage_clicked();

    void on_DoneButton2_clicked();

private:
    Ui::MainWindow *ui;     // ATT - main ui window

    /*******************************************************************
     *  QString getDreamStrArray();
     *     dream stadium text
     * *****************************************************************/
    QString getDreamStrArray();
    QString stadiumPathText = "";   // ATT - text to display path
    QString arrow = " --> \n";      // ATT - arrow for output
    string strArrow = " --> \n";    // ATT - arrow for output

    vector<string> dreamList;       // ATT - list of stadiums in trip
    /*******************************************************************
     *  void clearDreamList();
     *     delete all stadiums in the dream list
     * *****************************************************************/
    void clearDreamList();
    /*******************************************************************
     *  bool alreadyInDreamList(string stadiumName);
     *     check if stadium is already in the list
     * *****************************************************************/
    bool alreadyInDreamList(string stadiumName);    //IN - stadium name to chck
    /*******************************************************************
     *  void deleteDreamStadium(string stadiumName);
     *     delete stadium from dream list
     * *****************************************************************/
    void deleteDreamStadium(string stadiumName);    //IN - stadium to del

    //GRAPH
    graph g;        // ATT- graph object to handle display

    //SOUVENIR
    souvenirs s;    // ATT- souvenir object


    userInfo client;// ATT- info for the client

    //NEW STADIUMS ADDED
    List<stadium> newStadiumaAddedbyUser;
    List<stadium> getStadiumListALL();





};
#endif // MAINWINDOW_H
