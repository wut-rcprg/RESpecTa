class DiagramScene;

#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H

#include <QGraphicsScene>
#include "baseState.h"
#include "Graph.h"
#include "Model.h"


QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
class QMenu;
class QPointF;
class QGraphicsLineItem;
class QFont;
class QGraphicsTextItem;
class QColor;
QT_END_NAMESPACE
/**
*   Class representing a scene, on which the items are shown.
*/
class DiagramScene : public QGraphicsScene
{
    Q_OBJECT

public:


    DiagramScene(QMenu *itemMenu, QObject *parent,Model * newmod );
    /*QFont font() const
        { return myFont; }
    QColor textColor() const
        { return myTextColor; }
    QColor itemColor() const
        { return myItemColor; }
    QColor lineColor() const
        { return myLineColor; }
    void setLineColor(const QColor &color);
    void setTextColor(const QColor &color);
    void setItemColor(const QColor &color);*/
    /**
    *   Sets State, which will be inserted next into the scene.
    */
    void setToInsertState (BaseState * newState){toInsert = newState;}

    /**
    *   Sets attributes(condition, subtask) of the transition, which will be next inserted into the scene.
    */
    void setTransitionAttributes(std::pair<QString,QString> thePair){transitionAttributes=thePair;}
    /**
    *   Sets contextMenu, graphicsItem and colour for the inserted item (used while loading from XML).
    */
    void setItemParams(BaseState * toInsert);

    void checkIfFits(BaseState * state);

signals:
    void LineCanceled();
    void modeChanged(SceneMode mode);

    /**
    *   Signals, that a state has been inserted into the scene.
    */
    void itemInserted(BaseState *item);
    /**
    *   Signals, that a transition has been inserted into the scene.
    */
    void lineInserted(Transition * line);
    /**
    *   Signals, that an item has been selected on the scene.
    */
    void itemSelected(QGraphicsItem *item);
    /**
    *   Reports an error to the main window
    */
    void reportError(QString);

public slots:
    void setMode(SceneMode mode);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);

private:

    /**
    *   Pointer to the model of the task.
    */
    Model * mod;

    /**
    *   Pair holding attributes of the transition, which will be inserted.
    */
    std::pair<QString,QString> transitionAttributes;
    /**
    *   State, which will be next inserted into the scene.
    */
    BaseState * toInsert;
    /**
    *   Context menu for the state.
    */
    QMenu *myItemMenu;
    /**
    *   Mode of the scene, describing what will be done with the click events.
    */
    SceneMode myMode;
    /**
    *   Point representing the start of the line, which is being inserted.
    */
    QPointF startPoint;
    /**
    *   Line, which represents the Transition while it's being inserted.
    */
    QGraphicsLineItem *line;
};

#endif
