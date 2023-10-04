#ifndef SETTINGS_DATA_LOGGING_1PRESENTER_HPP
#define SETTINGS_DATA_LOGGING_1PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Settings_Data_Logging_1View;

class Settings_Data_Logging_1Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Settings_Data_Logging_1Presenter(Settings_Data_Logging_1View& v);

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

    virtual ~Settings_Data_Logging_1Presenter() {}

private:
    Settings_Data_Logging_1Presenter();

    Settings_Data_Logging_1View& view;
};

#endif // SETTINGS_DATA_LOGGING_1PRESENTER_HPP
