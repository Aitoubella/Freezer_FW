#ifndef SETTINGS_DATA_LOGGINGPRESENTER_HPP
#define SETTINGS_DATA_LOGGINGPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Settings_data_loggingView;

class Settings_data_loggingPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Settings_data_loggingPresenter(Settings_data_loggingView& v);

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

    virtual ~Settings_data_loggingPresenter() {}

private:
    Settings_data_loggingPresenter();

    Settings_data_loggingView& view;
};

#endif // SETTINGS_DATA_LOGGINGPRESENTER_HPP
