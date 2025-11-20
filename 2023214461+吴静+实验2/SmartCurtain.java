public class SmartCurtain extends SmartDevice {
    private int openPercentage;

    public SmartCurtain(String id, String name) {
        super(id, name);
        this.openPercentage = 0;
    }

    public void setOpenPercentage(int percent) {
        if (percent < 0 || percent > 100) {
            System.out.println("打开百分比必须在0-100之间");
            return;
        }
        this.openPercentage = percent;
        if (percent > 0) {
            super.turnOn();
        } else {
            super.turnOff();
        }
        System.out.println("窗帘打开" + percent + "%");
    }

    @Override
    public String getDeviceType() {
        return "智能窗帘";
    }
}
