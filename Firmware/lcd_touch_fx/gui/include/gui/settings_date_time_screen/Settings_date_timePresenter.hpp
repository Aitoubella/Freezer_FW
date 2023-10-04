#ifndef SETTINGS_DATE_TIMEPRESENTER_HPP
#define SETTINGS_DATE_TIMEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Settings_date_timeView;

class Settings_date_timePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Settings_date_timePresenter(Settings_date_timeView& v);

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

    virtual ~Settings_date_timePresenter() {}

private:
    Settings_date_timePresenter();

    Settings_date_timeView& view;
};

#endif // SETTINGS_DATE_TIMEPRESENTER_HPP
