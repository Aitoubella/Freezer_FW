#ifndef SETTINGS_TEMPERATUREPRESENTER_HPP
#define SETTINGS_TEMPERATUREPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Settings_temperatureView;

class Settings_temperaturePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Settings_temperaturePresenter(Settings_temperatureView& v);

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

    virtual ~Settings_temperaturePresenter() {}

private:
    Settings_temperaturePresenter();

    Settings_temperatureView& view;
};

#endif // SETTINGS_TEMPERATUREPRESENTER_HPP
