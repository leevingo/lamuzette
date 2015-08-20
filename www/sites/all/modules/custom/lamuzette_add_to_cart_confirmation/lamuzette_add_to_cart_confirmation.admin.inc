<?php

/**
 * @file
 * Administration settings for lamuzette add to cart confirmation message
 */

/**
 * Administration settings form.
 *
 * @return
 *   The completed form definition.
 */
function lamuzette_add_to_cart_confirmation_admin_settings() {
  $form = array();

  $form['lamuzette_add_to_cart_confirmation_settings'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Add to cart confirmation settings'),
    '#collapsible'  => FALSE,
    '#collapsed'    => FALSE,
  );
  $form['lamuzette_add_to_cart_confirmation_settings']['lamuzette_add_to_cart_confirmation_body'] = array(
    '#type'          => 'textarea',
    '#title'         => t('Body text'),
    '#default_value' => variable_get('lamuzette_add_to_cart_confirmation_body', ''),
    '#description'   => t('You can add the body text here'),
  );
  $form['lamuzette_add_to_cart_confirmation_settings']['lamuzette_add_to_cart_confirmation_footer'] = array(
    '#type'          => 'textarea',
    '#title'         => t('Footer text'),
    '#default_value' => variable_get('lamuzette_add_to_cart_confirmation_footer', ''),
    '#description'   => t('You can add the footer text here'),
  );

  return system_settings_form($form);
}
