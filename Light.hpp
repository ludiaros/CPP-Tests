#ifndef LIGHT_HPP
#define LIGHT_HPP

class Light : public sf::Sprite {

    public:
        Light(int radius, int intensity, int maxvalue) {

            lightTexture.create(radius*2, radius*2);

            for (unsigned int i=0; i<radius; ++i) {

                temp.setRadius(radius-i);
                temp.setOrigin(sf::Vector2f(-(i*1.f), -(i*1.f)));
                if (i*intensity <= maxvalue) {
                    temp.setFillColor(sf::Color(255, 255, 255, i*intensity));
                }
                lightTexture.draw(temp, sf::BlendNone);
            }

            setTexture(lightTexture.getTexture());
            setOrigin(getLocalBounds().width/2, getLocalBounds().height/2);
        }

    private:
        sf::RenderTexture lightTexture;
        sf::CircleShape temp;
};

#endif
