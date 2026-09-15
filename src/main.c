// piefight - Port automatico J2ME -> PSP
// Gerado por portador.py
// MIDlet: PieMidlet  Canvas: Animator

#include <pspkernel.h>
#include <string.h>
#include <stdlib.h>
#include "j2me_gfx.h"
#include "j2me_font.h"
#include "j2me_input.h"
#include "j2me_image.h"
#include "j2me_clip.h"
#include "j2me_runtime.h"
#include <stdint.h>

// ============================================
// TIPOS J2ME -> ponteiros opacos em C
// ============================================
typedef void* Image;
typedef void* Graphics;
typedef void* Font;
typedef void* String;
typedef void* Command;
typedef void* Display;
typedef void* Displayable;
typedef void* MIDlet;
typedef void* Canvas;
typedef void* Random;
typedef void* Timer;
typedef void* TimerTask;
typedef void* Vector;
typedef void* InputStream;
typedef void* DataInputStream;

PSP_MODULE_INFO("piefight", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER);

#define SCR_W 480
#define SCR_H 272

// ============================================
// FORWARD DECLARATIONS das classes do projeto
// ============================================
typedef struct Animator_s Animator;
typedef struct PieCanvas_s PieCanvas;
typedef struct PieMidlet_s PieMidlet;
typedef struct Score_s Score;
typedef struct Sprite_s Sprite;
typedef struct SpriteEvent_s SpriteEvent;
typedef struct SpriteListener_s SpriteListener;
typedef struct State_s State;

// ============================================
// ESTRUTURAS DE DADOS (traduzidas do J2ME)
// ============================================

// === Classe: Animator (extends Canvas) ===
// Padroes detectados: CANVAS, TEM_INPUT, TEM_RUN, USA_TIMER, USA_IMAGE
struct Animator_s {
    int             FRAME_WIDTH;  // FRAME_WIDTH (I)
    int             FRAME_HEIGHT;  // FRAME_HEIGHT (I)
    int             X;  // X (I)
    int             Y;  // Y (I)
    int             IMAGES;  // IMAGES (I)
    Sprite**        _window;  // _window ([Lorg/eaves/piefight/Sprite;)
    PieCanvas*      _parent;  // _parent (Lorg/eaves/piefight/PieCanvas;)
    Display*        _sound;  // _sound (Ljavax/microedition/lcdui/Display;)
    int             _width;  // _width (I)
    int             _height;  // _height (I)
    Random*         _r;  // _r (Ljava/util/Random;)
};

// === Classe: PieCanvas (extends Canvas) ===
// Padroes detectados: CANVAS, TEM_PAINT, TEM_INPUT, USA_TIMER, USA_IMAGE
struct PieCanvas_s {
    int             FRAME_WIDTH;  // FRAME_WIDTH (I)
    int             FRAME_HEIGHT;  // FRAME_HEIGHT (I)
    int             FRAME_DELAY;  // FRAME_DELAY (I)
    int             SUCK;  // SUCK (I)
    int             OK;  // OK (I)
    int             RULE;  // RULE (I)
    Font*           _mfont;  // _mfont (Ljavax/microedition/lcdui/Font;)
    Font*           _nfont;  // _nfont (Ljavax/microedition/lcdui/Font;)
    int             _mfontHeight;  // _mfontHeight (I)
    Image*          _offscreen;  // _offscreen (Ljavax/microedition/lcdui/Image;)
    Image*          _youSuck;  // _youSuck (Ljavax/microedition/lcdui/Image;)
    Image*          _youRule;  // _youRule (Ljavax/microedition/lcdui/Image;)
    Image*          _youOK;  // _youOK (Ljavax/microedition/lcdui/Image;)
    Timer*          _animate;  // _animate (Ljava/util/Timer;)
    Animator*       _sprites;  // _sprites (Lorg/eaves/piefight/Animator;)
    int             _currentFrame;  // _currentFrame (I)
    int             _maxFrame;  // _maxFrame (I)
    int             _width;  // _width (I)
    int             _height;  // _height (I)
    int             _running;  // _running (Z)
    int             MAX_AMMO;  // MAX_AMMO (I)
    int             _pieCount;  // _pieCount (I)
    int             _ammoFrameCount;  // _ammoFrameCount (I)
    int             _ammoDisplayX;  // _ammoDisplayX (I)
    int             _ammoDisplayY;  // _ammoDisplayY (I)
    int             _ammoDisplayDelta;  // _ammoDisplayDelta (I)
    int             _targetsHitX;  // _targetsHitX (I)
    int             _targetsLeftX;  // _targetsLeftX (I)
    int             _infoLineY;  // _infoLineY (I)
    int             _targetsHit;  // _targetsHit (I)
    int             _targetsLeft;  // _targetsLeft (I)
    int             _startTargets;  // _startTargets (I)
    int             _endLevel;  // _endLevel (I)
    int             _currentLevel;  // _currentLevel (I)
    int             _hitPercent;  // _hitPercent (I)
    int             _maxAlive;  // _maxAlive (I)
    int             _ammoRecoveryDelta;  // _ammoRecoveryDelta (I)
    PieMidlet*      _parent;  // _parent (Lorg/eaves/piefight/PieMidlet;)
    Display*        _display;  // _display (Ljavax/microedition/lcdui/Display;)
};

// === Classe: PieMidlet (extends MIDlet) ===
// Padroes detectados: MIDLET, TEM_STARTAPP, USA_IMAGE
struct PieMidlet_s {
    String*         NAME;  // NAME (Ljava/lang/String;)
    String*         NULL_VERSION;  // NULL_VERSION (Ljava/lang/String;)
    Command*        _exit;  // _exit (Ljavax/microedition/lcdui/Command;)
    Command*        _next;  // _next (Ljavax/microedition/lcdui/Command;)
    Command*        _scoreNext;  // _scoreNext (Ljavax/microedition/lcdui/Command;)
    int             _scoreNextAdded;  // _scoreNextAdded (Z)
    String*         _version;  // _version (Ljava/lang/String;)
    int             _started;  // _started (Z)
    int             _introDone;  // _introDone (Z)
    Display*        _display;  // _display (Ljavax/microedition/lcdui/Display;)
    PieCanvas*      _pie;  // _pie (Lorg/eaves/piefight/PieCanvas;)
};

// === Classe: Score (extends Object) ===
// Padroes detectados: nenhum
struct Score_s {
    String*         _scoreTxt;  // _scoreTxt (Ljava/lang/String;)
    String*         _thanksTxt;  // _thanksTxt (Ljava/lang/String;)
    Command*        _play;  // _play (Ljavax/microedition/lcdui/Command;)
    Command*        _exit;  // _exit (Ljavax/microedition/lcdui/Command;)
};

// === Classe: Sprite (extends Object) ===
// Padroes detectados: nenhum
struct Sprite_s {
    int             INTRO;  // INTRO (I)
    int             LIVE;  // LIVE (I)
    int             LEAVE;  // LEAVE (I)
    int             IDLE;  // IDLE (I)
    int             START;  // START (I)
    int             HIT;  // HIT (I)
    int             INTRO_MISS;  // INTRO_MISS (I)
    int             IDLE_MISS;  // IDLE_MISS (I)
    int             STATES;  // STATES (I)
    Image*          _strip;  // _strip (Ljavax/microedition/lcdui/Image;)
    State**         _state;  // _state ([Lorg/eaves/piefight/State;)
    int             _thrownAt;  // _thrownAt (I)
    SpriteListener* _listener;  // _listener (Lorg/eaves/piefight/SpriteListener;)
    int             _currentState;  // _currentState (I)
    int             _queueState;  // _queueState (I)
    int             _frameX;  // _frameX (I)
    int             _frameY;  // _frameY (I)
    int             _xpos;  // _xpos (I)
    int             _ypos;  // _ypos (I)
    int             _moved;  // _moved (Z)
    int             _painted;  // _painted (Z)
};

// === Classe: SpriteEvent (extends Object) ===
// Padroes detectados: nenhum
struct SpriteEvent_s {
    int             END_STATE;  // END_STATE (I)
    int             END_SPRITE;  // END_SPRITE (I)
    int             _event;  // _event (I)
};

// === Classe: SpriteListener (extends Object) ===
// Padroes detectados: nenhum
struct SpriteListener_s {
    int _vazio;
};

// === Classe: State (extends Object) ===
// Padroes detectados: nenhum
struct State_s {
    int             _start;  // _start (I)
    int             _end;  // _end (I)
    int             _frame;  // _frame (I)
};

// ============================================
// METODOS (traduzidos do bytecode)
// ============================================

// === Animator.Animator_constructor ((Lorg/eaves/piefight/PieCanvas;IILjavax/microedition/lcdui/Display;)V) ===
// Instrucoes: 123
// APIs usadas:
//   2x javax/microedition/lcdui/Image.createImage -> j2me_image_create
//   1x java/util/TimerTask.<init> -> ??? java/util/TimerTask.<init>
//   1x java/util/Date.<init> -> ??? java/util/Date.<init>
//   1x java/util/Date.getTime -> ??? java/util/Date.getTime
//   1x java/util/Random.<init> -> j2me_random_init
//   1x java/io/PrintStream.println -> ??? java/io/PrintStream.println
//   1x java/util/Random.nextInt -> j2me_random_next
//   1x java/lang/Math.abs -> abs
void Animator_constructor() {
    // TODO: traduzir logica do bytecode
}

// === Animator.Animator_guardState ((Lorg/eaves/piefight/Sprite;)V) ===
// Instrucoes: 17
void Animator_guardState() {
    // TODO: traduzir logica do bytecode
}

// === Animator.Animator_reset (()V) ===
// Instrucoes: 14
void Animator_reset() {
    // TODO: traduzir logica do bytecode
}

// === Animator.Animator_spriteAction ((Lorg/eaves/piefight/Sprite;Lorg/eaves/piefight/SpriteEvent;)V) ===
// Instrucoes: 62
// APIs usadas:
//   2x java/util/Random.nextInt -> j2me_random_next
//   2x java/lang/Math.abs -> abs
void Animator_spriteAction() {
    // TODO: traduzir logica do bytecode
}

// === Animator.Animator_keyPressed ((I)V) ===
// Instrucoes: 57
void Animator_keyPressed() {
    // TODO: traduzir logica do bytecode
}

// === Animator.Animator_draw ((Ljavax/microedition/lcdui/Graphics;)V) ===
// Instrucoes: 22
// APIs usadas:
//   1x javax/microedition/lcdui/Graphics.setClip -> j2me_clip_push
void Animator_draw() {
    // TODO: traduzir logica do bytecode
}

// === Animator.Animator_getFrame (()I) ===
// Instrucoes: 6
int Animator_getFrame() {
    // TODO: traduzir logica do bytecode
    return 0;  // TODO
}

// === Animator.Animator_targetsActive (()I) ===
// Instrucoes: 23
int Animator_targetsActive() {
    // TODO: traduzir logica do bytecode
    return 0;  // TODO
}

// === Animator.Animator_run (()V) ===
// Instrucoes: 23
// APIs usadas:
//   1x javax/microedition/lcdui/Canvas.repaint -> j2me_canvas_repaint
//   1x javax/microedition/lcdui/Canvas.serviceRepaints -> ??? javax/microedition/lcdui/Canvas.serviceRepaints
void Animator_run(void* self) {
    Animator* a = (Animator*)self;
    if (!a || !a->_parent) return;
    if (PieCanvas_isRunning(a->_parent)) {
        for (int i = 0; i < Animator_IMAGES; i++) {
            if (a->window && a->window[i]) Sprite_animate(a->window[i]);
        }
        j2me_canvas_repaint();
        j2me_canvas_serviceRepaints();
    }
}

// === PieCanvas.PieCanvas_constructor ((Lorg/eaves/piefight/PieMidlet;)V) ===
// Instrucoes: 139
// APIs usadas:
//   4x javax/microedition/lcdui/Image.createImage -> j2me_image_create
//   1x javax/microedition/lcdui/Canvas.<init> -> ??? javax/microedition/lcdui/Canvas.<init>
//   1x javax/microedition/lcdui/Display.getDisplay -> j2me_display_get
//   1x javax/microedition/lcdui/Canvas.getWidth -> j2me_canvas_w
//   1x javax/microedition/lcdui/Canvas.getHeight -> j2me_canvas_h
//   1x javax/microedition/lcdui/Canvas.isDoubleBuffered -> ??? javax/microedition/lcdui/Canvas.isDoubleBuffered
//   1x javax/microedition/midlet/MIDlet.getAppProperty -> ??? javax/microedition/midlet/MIDlet.getAppProperty
//   1x javax/microedition/lcdui/Font.getFont -> ??? javax/microedition/lcdui/Font.getFont
void PieCanvas_constructor() {
    // TODO: traduzir logica do bytecode
}

// === PieCanvas.PieCanvas_changeLevel ((I)V) ===
// Instrucoes: 209
void PieCanvas_changeLevel() {
    // TODO: traduzir logica do bytecode
}

// === PieCanvas.PieCanvas_keyPressed ((I)V) ===
// Instrucoes: 14
void PieCanvas_keyPressed(int arg0) {
    PieCanvas* s = (PieCanvas*)_self;
    if (!s) return;
    int n = arg0 - 48;
    if (n > 0 && n < 7 && s->sprites != 0) {
        Animator_keyPressed(s->sprites, n);
    }
}

// === PieCanvas.PieCanvas_ammoAvailable (()Z) ===
// Instrucoes: 13
int PieCanvas_ammoAvailable() {
    // TODO: traduzir logica do bytecode
    return 0;  // TODO
}

// === PieCanvas.PieCanvas_showNotify (()V) ===
// Instrucoes: 20
// APIs usadas:
//   1x java/util/Timer.<init> -> ??? java/util/Timer.<init>
//   1x java/util/Timer.scheduleAtFixedRate -> ??? java/util/Timer.scheduleAtFixedRate
void PieCanvas_showNotify() {
    // TODO: traduzir logica do bytecode
}

// === PieCanvas.PieCanvas_hideNotify (()V) ===
// Instrucoes: 4
void PieCanvas_hideNotify() {
    // TODO: traduzir logica do bytecode
}

// === PieCanvas.PieCanvas_isRunning (()Z) ===
// Instrucoes: 3
int PieCanvas_isRunning() {
    // TODO: traduzir logica do bytecode
    return 0;  // TODO
}

// === PieCanvas.PieCanvas_maxAlive (()I) ===
// Instrucoes: 3
int PieCanvas_maxAlive() {
    // TODO: traduzir logica do bytecode
    return 0;  // TODO
}

// === PieCanvas.PieCanvas_targetShown (()V) ===
// Instrucoes: 16
void PieCanvas_targetShown() {
    // TODO: traduzir logica do bytecode
}

// === PieCanvas.PieCanvas_targetsLeft (()Z) ===
// Instrucoes: 7
int PieCanvas_targetsLeft() {
    // TODO: traduzir logica do bytecode
    return 0;  // TODO
}

// === PieCanvas.PieCanvas_nextLevel (()V) ===
// Instrucoes: 15
// APIs usadas:
//   1x java/lang/System.gc -> ??? java/lang/System.gc
void PieCanvas_nextLevel() {
    // TODO: traduzir logica do bytecode
}

// === PieCanvas.PieCanvas_targetHit (()V) ===
// Instrucoes: 13
void PieCanvas_targetHit() {
    // TODO: traduzir logica do bytecode
}

// === PieCanvas.PieCanvas_drawScore ((Ljavax/microedition/lcdui/Graphics;)V) ===
// Instrucoes: 194
// APIs usadas:
//   10x java/lang/StringBuffer.append -> ??? java/lang/StringBuffer.append
//   6x javax/microedition/lcdui/Graphics.drawString -> j2me_font_draw
//   5x java/lang/StringBuffer.<init> -> ??? java/lang/StringBuffer.<init>
//   5x java/lang/StringBuffer.toString -> ??? java/lang/StringBuffer.toString
//   2x javax/microedition/lcdui/Graphics.setColor -> j2me_gfx_set_color
//   1x javax/microedition/lcdui/Graphics.fillRect -> j2me_gfx_fill_rect
//   1x javax/microedition/lcdui/Graphics.setFont -> j2me_noop
//   1x javax/microedition/lcdui/Graphics.drawImage -> j2me_image_blit
void PieCanvas_drawScore() {
    // TODO: traduzir logica do bytecode
}

// === PieCanvas.PieCanvas_endScore (()V) ===
// Instrucoes: 4
void PieCanvas_endScore() {
    // TODO: traduzir logica do bytecode
}

// === PieCanvas.PieCanvas_drawGame ((Ljavax/microedition/lcdui/Graphics;)V) ===
// Instrucoes: 139
// APIs usadas:
//   3x javax/microedition/lcdui/Graphics.setColor -> j2me_gfx_set_color
//   3x javax/microedition/lcdui/Graphics.fillRect -> j2me_gfx_fill_rect
//   3x javax/microedition/lcdui/Graphics.drawString -> j2me_font_draw
//   2x javax/microedition/lcdui/Graphics.setFont -> j2me_noop
//   2x java/lang/Integer.toString -> j2me_int_to_string
//   1x javax/microedition/lcdui/Graphics.setClip -> j2me_clip_push
//   1x javax/microedition/lcdui/Graphics.drawRect -> ??? javax/microedition/lcdui/Graphics.drawRect
void PieCanvas_drawGame() {
    // TODO: traduzir logica do bytecode
}

// === PieCanvas.PieCanvas_paint ((Ljavax/microedition/lcdui/Graphics;)V) ===
// Instrucoes: 43
// APIs usadas:
//   1x javax/microedition/lcdui/Image.getGraphics -> j2me_image_get_graphics
//   1x java/lang/System.gc -> ??? java/lang/System.gc
//   1x javax/microedition/lcdui/Graphics.drawImage -> j2me_image_blit
void PieCanvas_paint(void* arg1) {
    PieCanvas* s = (PieCanvas*)_self;
    if (!s) return;
    void* g = arg1;
    if (s->offscreen != 0) g = j2me_image_get_graphics(s->offscreen);
    if (s->endLevel > 0) {
        PieCanvas_drawScore(s, g);
        if (s->endLevel > 1) {
            s->endLevel = 0;
            PieCanvas_nextLevel(s);
            if (s->_parent) PieMidlet_resetScoreNext(s->_parent);
            j2me_gc();
        }
    } else {
        PieCanvas_drawGame(s, g);
    }
    if (arg1 != s->offscreen && s->offscreen) {
        j2me_image_blit((J2MEImage*)s->offscreen, 0, 0);
    }
}

// === PieMidlet.PieMidlet_constructor (()V) ===
// Instrucoes: 61
// APIs usadas:
//   3x javax/microedition/lcdui/Command.<init> -> ??? javax/microedition/lcdui/Command.<init>
//   1x javax/microedition/midlet/MIDlet.<init> -> ??? javax/microedition/midlet/MIDlet.<init>
//   1x javax/microedition/midlet/MIDlet.getAppProperty -> ??? javax/microedition/midlet/MIDlet.getAppProperty
void PieMidlet_constructor() {
    // TODO: traduzir logica do bytecode
}

// === PieMidlet.PieMidlet_startApp (()V) ===
// Instrucoes: 68
// APIs usadas:
//   2x javax/microedition/lcdui/Displayable.addCommand -> ??? javax/microedition/lcdui/Displayable.addCommand
//   2x javax/microedition/lcdui/Displayable.setCommandListener -> ??? javax/microedition/lcdui/Displayable.setCommandListener
//   1x javax/microedition/lcdui/Display.getDisplay -> j2me_display_get
//   1x javax/microedition/lcdui/Image.createImage -> j2me_image_create
//   1x javax/microedition/lcdui/ImageItem.<init> -> ??? javax/microedition/lcdui/ImageItem.<init>
//   1x javax/microedition/lcdui/Form.<init> -> ??? javax/microedition/lcdui/Form.<init>
//   1x javax/microedition/lcdui/Form.append -> ??? javax/microedition/lcdui/Form.append
//   1x javax/microedition/lcdui/Display.setCurrent -> j2me_display_set
void PieMidlet_startApp() {
    // TODO: traduzir logica do bytecode
}

// === PieMidlet.PieMidlet_newPieCanvas (()V) ===
// Instrucoes: 10
// APIs usadas:
//   1x javax/microedition/lcdui/Display.setCurrent -> j2me_display_set
//   1x java/lang/System.gc -> ??? java/lang/System.gc
void PieMidlet_newPieCanvas() {
    // TODO: traduzir logica do bytecode
}

// === PieMidlet.PieMidlet_doScoreNext (()V) ===
// Instrucoes: 12
// APIs usadas:
//   1x javax/microedition/lcdui/Displayable.addCommand -> ??? javax/microedition/lcdui/Displayable.addCommand
void PieMidlet_doScoreNext() {
    // TODO: traduzir logica do bytecode
}

// === PieMidlet.PieMidlet_resetScoreNext (()V) ===
// Instrucoes: 4
void PieMidlet_resetScoreNext() {
    // TODO: traduzir logica do bytecode
}

// === PieMidlet.PieMidlet_commandAction ((Ljavax/microedition/lcdui/Command;Ljavax/microedition/lcdui/Displayable;)V) ===
// Instrucoes: 39
// APIs usadas:
//   1x javax/microedition/lcdui/Displayable.removeCommand -> ??? javax/microedition/lcdui/Displayable.removeCommand
//   1x java/lang/Thread.sleep -> j2me_sleep
//   1x java/lang/System.gc -> ??? java/lang/System.gc
void PieMidlet_commandAction() {
    // TODO: traduzir logica do bytecode
}

// === PieMidlet.PieMidlet_pauseApp (()V) ===
// Instrucoes: 1
void PieMidlet_pauseApp() {
    // TODO: traduzir logica do bytecode
}

// === PieMidlet.PieMidlet_destroyApp ((Z)V) ===
// Instrucoes: 1
void PieMidlet_destroyApp() {
    // TODO: traduzir logica do bytecode
}

// === PieMidlet.PieMidlet_exit (()V) ===
// Instrucoes: 6
// APIs usadas:
//   1x javax/microedition/midlet/MIDlet.notifyDestroyed -> ??? javax/microedition/midlet/MIDlet.notifyDestroyed
void PieMidlet_exit() {
    // TODO: traduzir logica do bytecode
}

// === Score.Score_constructor ((I)V) ===
// Instrucoes: 46
// APIs usadas:
//   2x javax/microedition/lcdui/Command.<init> -> ??? javax/microedition/lcdui/Command.<init>
//   2x java/lang/StringBuffer.append -> ??? java/lang/StringBuffer.append
//   2x javax/microedition/lcdui/Form.append -> ??? javax/microedition/lcdui/Form.append
//   2x javax/microedition/lcdui/Displayable.addCommand -> ??? javax/microedition/lcdui/Displayable.addCommand
//   1x javax/microedition/lcdui/Form.<init> -> ??? javax/microedition/lcdui/Form.<init>
//   1x java/lang/StringBuffer.<init> -> ??? java/lang/StringBuffer.<init>
//   1x java/lang/Integer.toString -> j2me_int_to_string
//   1x java/lang/StringBuffer.toString -> ??? java/lang/StringBuffer.toString
void Score_constructor() {
    // TODO: traduzir logica do bytecode
}

// === Score.Score_getPlayCommand (()Ljavax/microedition/lcdui/Command;) ===
// Instrucoes: 3
Command* Score_getPlayCommand() {
    // TODO: traduzir logica do bytecode
    return 0;  // TODO
}

// === Score.Score_getExitCommand (()Ljavax/microedition/lcdui/Command;) ===
// Instrucoes: 3
Command* Score_getExitCommand() {
    // TODO: traduzir logica do bytecode
    return 0;  // TODO
}

// === Sprite.Sprite_constructor ((Ljavax/microedition/lcdui/Image;)V) ===
// Instrucoes: 16
// APIs usadas:
//   1x java/lang/Object.<init> -> j2me_noop
void Sprite_constructor() {
    // TODO: traduzir logica do bytecode
}

// === Sprite.Sprite_start (()V) ===
// Instrucoes: 76
void Sprite_start() {
    // TODO: traduzir logica do bytecode
}

// === Sprite.Sprite_throwAt (()V) ===
// Instrucoes: 4
void Sprite_throwAt() {
    // TODO: traduzir logica do bytecode
}

// === Sprite.Sprite_setListener ((Lorg/eaves/piefight/SpriteListener;)V) ===
// Instrucoes: 4
void Sprite_setListener() {
    // TODO: traduzir logica do bytecode
}

// === Sprite.Sprite_nextState (()V) ===
// Instrucoes: 18
void Sprite_nextState() {
    // TODO: traduzir logica do bytecode
}

// === Sprite.Sprite_action ((I)V) ===
// Instrucoes: 13
void Sprite_action() {
    // TODO: traduzir logica do bytecode
}

// === Sprite.Sprite_draw ((Ljavax/microedition/lcdui/Graphics;)V) ===
// Instrucoes: 83
// APIs usadas:
//   1x javax/microedition/lcdui/Graphics.clipRect -> ??? javax/microedition/lcdui/Graphics.clipRect
//   1x javax/microedition/lcdui/Graphics.drawImage -> j2me_image_blit
//   1x javax/microedition/lcdui/Graphics.fillRect -> j2me_gfx_fill_rect
void Sprite_draw() {
    // TODO: traduzir logica do bytecode
}

// === Sprite.Sprite_animate (()V) ===
// Instrucoes: 24
void Sprite_animate() {
    // TODO: traduzir logica do bytecode
}

// === Sprite.Sprite_clear ((Ljavax/microedition/lcdui/Graphics;II)V) ===
// Instrucoes: 17
// APIs usadas:
//   2x javax/microedition/lcdui/Graphics.setColor -> j2me_gfx_set_color
//   1x javax/microedition/lcdui/Graphics.fillRect -> j2me_gfx_fill_rect
void Sprite_clear() {
    // TODO: traduzir logica do bytecode
}

// === Sprite.Sprite_setX ((I)V) ===
// Instrucoes: 4
void Sprite_setX() {
    // TODO: traduzir logica do bytecode
}

// === Sprite.Sprite_setY ((I)V) ===
// Instrucoes: 4
void Sprite_setY() {
    // TODO: traduzir logica do bytecode
}

// === Sprite.Sprite_frameX ((I)V) ===
// Instrucoes: 4
void Sprite_frameX() {
    // TODO: traduzir logica do bytecode
}

// === Sprite.Sprite_frameY ((I)V) ===
// Instrucoes: 4
void Sprite_frameY() {
    // TODO: traduzir logica do bytecode
}

// === Sprite.Sprite_getState (()I) ===
// Instrucoes: 3
int Sprite_getState() {
    // TODO: traduzir logica do bytecode
    return 0;  // TODO
}

// === Sprite.Sprite_setState ((I)V) ===
// Instrucoes: 13
void Sprite_setState() {
    // TODO: traduzir logica do bytecode
}

// === Sprite.Sprite_getFrame (()I) ===
// Instrucoes: 7
int Sprite_getFrame() {
    // TODO: traduzir logica do bytecode
    return 0;  // TODO
}

// === Sprite.Sprite_frameXPos ((I)I) ===
// Instrucoes: 5
int Sprite_frameXPos() {
    // TODO: traduzir logica do bytecode
    return 0;  // TODO
}

// === Sprite.Sprite_frameYPos ((I)I) ===
// Instrucoes: 3
int Sprite_frameYPos() {
    // TODO: traduzir logica do bytecode
    return 0;  // TODO
}

// === SpriteEvent.SpriteEvent_constructor (()V) ===
// Instrucoes: 3
// APIs usadas:
//   1x java/lang/Object.<init> -> j2me_noop
void SpriteEvent_constructor() {
    // TODO: traduzir logica do bytecode
}

// === SpriteEvent.SpriteEvent_constructor_2 ((I)V) ===
// Instrucoes: 6
// APIs usadas:
//   1x java/lang/Object.<init> -> j2me_noop
void SpriteEvent_constructor_2() {
    // TODO: traduzir logica do bytecode
}

// === SpriteEvent.SpriteEvent_getEvent (()I) ===
// Instrucoes: 3
int SpriteEvent_getEvent() {
    // TODO: traduzir logica do bytecode
    return 0;  // TODO
}

// === State.State_constructor ((II)V) ===
// Instrucoes: 18
// APIs usadas:
//   1x java/lang/Object.<init> -> j2me_noop
void State_constructor() {
    // TODO: traduzir logica do bytecode
}

// === State.State_next (()I) ===
// Instrucoes: 27
int State_next() {
    // TODO: traduzir logica do bytecode
    return 0;  // TODO
}

// === State.State_prev (()I) ===
// Instrucoes: 27
int State_prev() {
    // TODO: traduzir logica do bytecode
    return 0;  // TODO
}

// === State.State_init (()V) ===
// Instrucoes: 5
void State_init(void* self) {
    State* s = (State*)self;
    if (!s) return;
    s->frame = s->start;
}

// === State.State_current (()I) ===
// Instrucoes: 3
int State_current() {
    // TODO: traduzir logica do bytecode
    return 0;  // TODO
}

// === State.State_atEnd (()Z) ===
// Instrucoes: 9
int State_atEnd() {
    // TODO: traduzir logica do bytecode
    return 0;  // TODO
}

// ============================================
// GAME LOOP PRINCIPAL
// ============================================

int main(void) {
    j2me_gfx_init();
    j2me_input_init();
    j2me_random_init();

    while (1) {
        j2me_input_update();
        if (j2me_input_should_quit()) break;

        j2me_gfx_begin_frame();
        j2me_gfx_clear(0x101020);

        // TODO: chamar metodos do jogo aqui
        // PieMidlet_startApp();
        // Animator_paint();

        j2me_gfx_flip();
    }

    j2me_gfx_shutdown();
    sceKernelExitGame();
    return 0;
}
