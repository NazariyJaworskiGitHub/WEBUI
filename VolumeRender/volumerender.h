#ifndef VOLUMERENDER_H
#define VOLUMERENDER_H

// For usage of Qt native macro SIGNAL() and SLOT()
#ifndef WT_NO_SLOT_MACROS
#define WT_NO_SLOT_MACROS
#endif // WT_NO_SLOT_MACROS

// For disabling boost warnings
#ifndef BOOST_SIGNALS_NO_DEPRECATION_WARNING
#define BOOST_SIGNALS_NO_DEPRECATION_WARNING
#endif // BOOST_SIGNALS_NO_DEPRECATION_WARNING

#include <Wt/WGLWidget>
#include <Wt/WMatrix4x4>

// User-Side or Server-Side UI control
//#define USER_SIDE_CONTROL

using namespace Wt;

namespace Web
{

class VolumeRender : public WGLWidget
{
    private: Program                _shaderProgramFirst;
    private: Program                _shaderProgramSecond;
    private: Framebuffer            _framebuffer;
    private: Texture                _framebufferTexture;
    private: Renderbuffer           _renderbuffer;

    private: Buffer                 _boxVerticesBuffer;
    private: Buffer                 _boxColorsBuffer;

    private: float _innerBottomCutLevel = 0.0f; // min
    public : float getInnerBottomCutLevel() const noexcept {return _innerBottomCutLevel;}
    public : void setInnerBottomCutLevel(float newBottomCutLevel) noexcept {
            _innerBottomCutLevel = newBottomCutLevel;}

    private: float _innerTopCutLevel = 1.0f;    // max
    public : float getInnerTopCutLevel() const noexcept {return _innerTopCutLevel;}
    public : void setInnerTopCutLevel(float newTopCutLevel) noexcept {
            _innerTopCutLevel = newTopCutLevel;}

    // set on construction, can't be changed
    private: const int _RVESize;
    private: const float * const _ptrToRVEdata = nullptr;
    private: Texture _RVEtexture;

    public: VolumeRender(int size, float *data, WContainerWidget *parent);

    private: void _preloadRVEIntoGrayscaleTexture();
    private: void _initShaders();
    private: void _initBox();
    private: void _initFBO();


    public: void initializeGL() override;
    public: void paintGL() override;
    public: void resizeGL(int width, int height) override;
    public: void updateGL() override;

    public: ~VolumeRender();

    // User JavaScript conrol
#ifdef USER_SIDE_CONTROL
    /// \todo there are too many matrices! combine them
    private: JavaScriptMatrix4x4    _mModel;
    private: JavaScriptMatrix4x4    _mControl;
    private: JavaScriptMatrix4x4    _mWorld;
    private: JavaScriptMatrix4x4    _mProj;
    private: JavaScriptMatrix4x4    _mScene;
    ///Multiplies Projection, World-View and Model matrices at client side
    private: void _buildSceneMatrix();
    private: JSlot                  _onMouseWentDownJSlot;
    private: JSlot                  _onMouseDraggedJSlot;
    private: JSlot                  _onMouseWheelJSlot;
    /// See native WGLWidget::glObjJsRef()
    private: std::string _glObjJsRef();
    /// Makes user-side JavaScript callback functions for view mouse-control
    private: void _initializeUserSideMouseControl();
    private: void _drawBox(Program &program, JavaScriptMatrix4x4 &sceneMatrix);
#else
    /// \todo there are too many matrices! combine them
    private: WMatrix4x4             _mModel;
    private: WMatrix4x4             _mControl;
    private: WMatrix4x4             _mWorld;
    private: WMatrix4x4             _mProj;
    private: WMatrix4x4             _mScene;    // =Proj*World*Control*Model
    private: int _oldMouseCoors[2];
    private: void _onMouseWentDown(const WMouseEvent &event);
    private: void _onMouseDragged(const WMouseEvent &event);
    private: void _onMouseWheel(const WMouseEvent &event);
    private: void _drawBox(Program &program, WMatrix4x4 &sceneMatrix);
#endif //USER_SIDE_CONTROL
};

#ifdef USER_SIDE_CONTROL
/// See WGLWidget::makeFloat() -> Utils::round_js_str() -> round_js_str()
/// at src/web/WebUtils.c
/// \todo replace this function
static inline char *generic_double_to_str(double d, char *buf)
{
    if (!boost::math::isnan(d)) {
        if (!boost::math::isinf(d)) {
            sprintf(buf, "%.7e", d);
        } else {
            if (d > 0) {
                sprintf(buf, "Infinity");
            } else {
                sprintf(buf, "-Infinity");
            }
        }
    } else {
        sprintf(buf, "NaN");
    }
    return buf;
}
#endif //USER_SIDE_CONTROL
}

#endif // VOLUMERENDER_H
