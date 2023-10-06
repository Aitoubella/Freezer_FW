#ifndef SETTINGS_TEMPERATURE_SET_POINT_FREEZE_BACKPRESENTER_HPP
#define SETTINGS_TEMPERATURE_SET_POINT_FREEZE_BACKPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Settings_temperature_set_point_freeze_backView;

class Settings_temperature_set_point_freeze_backPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Settings_temperature_set_point_freeze_backPresenter(Settings_temperature_set_point_freeze_backView& v);

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

    virtual ~Settings_temperature_set_point_freeze_backPresenter() {}

private:
    Settings_temperature_set_point_freeze_backPresenter();

    Settings_temperature_set_point_freeze_backView& view;
};

#endif // SETTINGS_TEMPERATURE_SET_POINT_FREEZE_BACKPRESENTER_HPP
