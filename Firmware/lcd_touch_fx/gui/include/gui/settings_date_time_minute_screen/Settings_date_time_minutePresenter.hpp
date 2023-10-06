#ifndef SETTINGS_DATE_TIME_MINUTEPRESENTER_HPP
#define SETTINGS_DATE_TIME_MINUTEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Settings_date_time_minuteView;

class Settings_date_time_minutePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Settings_date_time_minutePresenter(Settings_date_time_minuteView& v);

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

    virtual ~Settings_date_time_minutePresenter() {}

private:
    Settings_date_time_minutePresenter();

    Settings_date_time_minuteView& view;
};

#endif // SETTINGS_DATE_TIME_MINUTEPRESENTER_HPP
