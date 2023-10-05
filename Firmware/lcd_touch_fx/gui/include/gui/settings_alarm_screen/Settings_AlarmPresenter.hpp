#ifndef SETTINGS_ALARMPRESENTER_HPP
#define SETTINGS_ALARMPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Settings_AlarmView;

class Settings_AlarmPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Settings_AlarmPresenter(Settings_AlarmView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Settings_AlarmPresenter() {}

private:
    Settings_AlarmPresenter();

    Settings_AlarmView& view;
};

#endif // SETTINGS_ALARMPRESENTER_HPP
