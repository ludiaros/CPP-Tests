#ifndef LIGHTSPRITE_HPP
#define LIGHTSPRITE_HPP

#define SCR_W 600
#define SCR_H 600

class LightSprite : public sf::Sprite {

    public:

        LightSprite() {
            m_layer.create(SCR_W, SCR_H);
            setTexture(m_layer.getTexture());
        }

        void update(float x, float y) {

            m_light.setPosition(sf::Vector2f((float) x, (float) y));
            m_layer.clear(sf::Color(0, 0, 0, 240));
            m_layer.draw(m_light, sf::BlendNone);
            m_layer.display();
        }

        void addLight(int radius, float x, float y) {

            m_lightTexture.create(radius*2, radius*2);//Textura que contiene el circulo iluminado

            m_lightTexture.clear(sf::Color(0, 0, 0, 0));

            for (unsigned int i=0; i<radius; ++i) {

                temp.setRadius(radius-(i*1.f));
                temp.setOrigin(sf::Vector2f(-(i*1.f), -(i*1.f)));
                temp.setFillColor(sf::Color(0, 0, 0, 240-(i*(240/radius))));
                temp.setPosition(sf::Vector2f(0.f, 0.f));

                m_lightTexture.draw(temp, sf::BlendNone);
            }

            m_lightTexture.display();

            m_light.setTexture(m_lightTexture.getTexture(), true);
            m_light.setOrigin(m_light.getLocalBounds().width/2, m_light.getLocalBounds().height/2);
            m_light.setPosition(x, y);
        }

        void removeLight() {
            m_light = Sprite();
        }

    private:

        sf::RenderTexture m_lightTexture;
        sf::RenderTexture m_layer;

        sf::Sprite m_light;

        sf::CircleShape temp;
};

#endif
