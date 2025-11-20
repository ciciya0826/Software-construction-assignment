public class SmartLight extends SmartDevice {
    private int brightness;

    public SmartLight(String id, String name) {
        super(id, name);
        this.brightness = 50;
    }

    public void setBrightness(int level) {
        if (level < 0 || level > 100) {
            System.out.println("亮度必须在0-100之间");
            return;
        }
        this.brightness = level;
        System.out.println(getDeviceType() + "亮度已设为" + brightness);
    }

    public int getBrightness() {
        return brightness;
    }

    @Override
    public String getDeviceType() {
        return "智能灯";
    }
}
